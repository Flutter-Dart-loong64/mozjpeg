/*
 * jcsample-lasx.c - downsampling (LoongArch LASX)
 *
 * Copyright (C) 2026, LoongArch Flutter/Dart port contributors.
 *
 * For conditions of distribution and use, see copyright notice in jsimdext.inc.
 */

#define JPEG_INTERNALS
#include "../../jinclude.h"
#include "../../jpeglib.h"
#include "../../jsimd.h"
#include "../../jdct.h"
#include "../../jsimddct.h"
#include "../jsimd.h"

#include <stdint.h>
#include <string.h>
#include <lasxintrin.h>

static inline __m256i
lasx_loadu_256(const void *p)
{
  return __lasx_xvld((void *)p, 0);
}

static inline void
lasx_store16_u8(JSAMPROW out, __m256i h)
{
  __m256i b = __lasx_xvpickev_b(h, h);
  uint8_t packed[32];

  __lasx_xvst(b, packed, 0);
  memcpy(out, packed, 16);
}

void
jsimd_h2v1_downsample_lasx(JDIMENSION width_in_blocks, int v_samp_factor,
                           JSAMPARRAY input_data, JSAMPARRAY output_data)
{
  const __m256i zero = __lasx_xvldi(0);
  const v16i16 bias_v = {
    0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1
  };
  JDIMENSION output_cols = width_in_blocks * DCTSIZE;
  int outrow;

  for (outrow = 0; outrow < v_samp_factor; outrow++) {
    JSAMPROW inptr = input_data[outrow];
    JSAMPROW outptr = output_data[outrow];
    JDIMENSION outcol = 0;
    int bias = 0;

    for (; outcol + 16 <= output_cols; outcol += 16) {
      __m256i samples = lasx_loadu_256(inptr);
      __m256i even = __lasx_xvilvl_b(zero,
                                     __lasx_xvpickev_b(samples, samples));
      __m256i odd = __lasx_xvilvl_b(zero,
                                    __lasx_xvpickod_b(samples, samples));
      __m256i sum = __lasx_xvadd_h(__lasx_xvadd_h(even, odd),
                                   (__m256i)bias_v);

      sum = __lasx_xvsrai_h(sum, 1);
      lasx_store16_u8(outptr, sum);
      inptr += 32;
      outptr += 16;
    }

    for (; outcol < output_cols; outcol++) {
      *outptr++ = (JSAMPLE)((inptr[0] + inptr[1] + bias) >> 1);
      bias ^= 1;
      inptr += 2;
    }
  }
}

void
jsimd_h2v2_downsample_lasx(JDIMENSION width_in_blocks, int v_samp_factor,
                           JSAMPARRAY input_data, JSAMPARRAY output_data)
{
  const __m256i zero = __lasx_xvldi(0);
  const v16i16 bias_v = {
    1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2
  };
  JDIMENSION output_cols = width_in_blocks * DCTSIZE;
  int inrow = 0, outrow;

  for (outrow = 0; outrow < v_samp_factor; outrow++) {
    JSAMPROW inptr0 = input_data[inrow];
    JSAMPROW inptr1 = input_data[inrow + 1];
    JSAMPROW outptr = output_data[outrow];
    JDIMENSION outcol = 0;
    int bias = 1;

    for (; outcol + 16 <= output_cols; outcol += 16) {
      __m256i row0 = lasx_loadu_256(inptr0);
      __m256i row1 = lasx_loadu_256(inptr1);
      __m256i even0 = __lasx_xvilvl_b(zero,
                                      __lasx_xvpickev_b(row0, row0));
      __m256i odd0 = __lasx_xvilvl_b(zero,
                                     __lasx_xvpickod_b(row0, row0));
      __m256i even1 = __lasx_xvilvl_b(zero,
                                      __lasx_xvpickev_b(row1, row1));
      __m256i odd1 = __lasx_xvilvl_b(zero,
                                     __lasx_xvpickod_b(row1, row1));
      __m256i sum = __lasx_xvadd_h(__lasx_xvadd_h(even0, odd0),
                                   __lasx_xvadd_h(even1, odd1));

      sum = __lasx_xvadd_h(sum, (__m256i)bias_v);
      sum = __lasx_xvsrai_h(sum, 2);
      lasx_store16_u8(outptr, sum);
      inptr0 += 32;
      inptr1 += 32;
      outptr += 16;
    }

    for (; outcol < output_cols; outcol++) {
      *outptr++ =
        (JSAMPLE)((inptr0[0] + inptr0[1] + inptr1[0] + inptr1[1] + bias) >> 2);
      bias ^= 3;
      inptr0 += 2;
      inptr1 += 2;
    }
    inrow += 2;
  }
}
