/*
 * jcsample-lsx.c - downsampling (LoongArch LSX)
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
#include <lsxintrin.h>

static inline __m128i
lsx_loadu_128(const void *p)
{
  return __lsx_vld((void *)p, 0);
}

static inline void
lsx_store8_u8(JSAMPROW out, __m128i h)
{
  __m128i b = __lsx_vpickev_b(h, h);
  uint64_t packed;

  memcpy(&packed, &b, sizeof(packed));
  memcpy(out, &packed, sizeof(packed));
}

void
jsimd_h2v1_downsample_lsx(JDIMENSION width_in_blocks, int v_samp_factor,
                          JSAMPARRAY input_data, JSAMPARRAY output_data)
{
  const __m128i zero = __lsx_vldi(0);
  const v8i16 bias_v = { 0, 1, 0, 1, 0, 1, 0, 1 };
  JDIMENSION output_cols = width_in_blocks * DCTSIZE;
  int outrow;

  for (outrow = 0; outrow < v_samp_factor; outrow++) {
    JSAMPROW inptr = input_data[outrow];
    JSAMPROW outptr = output_data[outrow];
    JDIMENSION outcol = 0;
    int bias = 0;

    for (; outcol + 8 <= output_cols; outcol += 8) {
      __m128i samples = lsx_loadu_128(inptr);
      __m128i even = __lsx_vilvl_b(zero, __lsx_vpickev_b(samples, samples));
      __m128i odd = __lsx_vilvl_b(zero, __lsx_vpickod_b(samples, samples));
      __m128i sum = __lsx_vadd_h(__lsx_vadd_h(even, odd), (__m128i)bias_v);

      sum = __lsx_vsrai_h(sum, 1);
      lsx_store8_u8(outptr, sum);
      inptr += 16;
      outptr += 8;
    }

    for (; outcol < output_cols; outcol++) {
      *outptr++ = (JSAMPLE)((inptr[0] + inptr[1] + bias) >> 1);
      bias ^= 1;
      inptr += 2;
    }
  }
}

void
jsimd_h2v2_downsample_lsx(JDIMENSION width_in_blocks, int v_samp_factor,
                          JSAMPARRAY input_data, JSAMPARRAY output_data)
{
  const __m128i zero = __lsx_vldi(0);
  const v8i16 bias_v = { 1, 2, 1, 2, 1, 2, 1, 2 };
  JDIMENSION output_cols = width_in_blocks * DCTSIZE;
  int inrow = 0, outrow;

  for (outrow = 0; outrow < v_samp_factor; outrow++) {
    JSAMPROW inptr0 = input_data[inrow];
    JSAMPROW inptr1 = input_data[inrow + 1];
    JSAMPROW outptr = output_data[outrow];
    JDIMENSION outcol = 0;
    int bias = 1;

    for (; outcol + 8 <= output_cols; outcol += 8) {
      __m128i row0 = lsx_loadu_128(inptr0);
      __m128i row1 = lsx_loadu_128(inptr1);
      __m128i even0 = __lsx_vilvl_b(zero, __lsx_vpickev_b(row0, row0));
      __m128i odd0 = __lsx_vilvl_b(zero, __lsx_vpickod_b(row0, row0));
      __m128i even1 = __lsx_vilvl_b(zero, __lsx_vpickev_b(row1, row1));
      __m128i odd1 = __lsx_vilvl_b(zero, __lsx_vpickod_b(row1, row1));
      __m128i sum = __lsx_vadd_h(__lsx_vadd_h(even0, odd0),
                                 __lsx_vadd_h(even1, odd1));

      sum = __lsx_vadd_h(sum, (__m128i)bias_v);
      sum = __lsx_vsrai_h(sum, 2);
      lsx_store8_u8(outptr, sum);
      inptr0 += 16;
      inptr1 += 16;
      outptr += 8;
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
