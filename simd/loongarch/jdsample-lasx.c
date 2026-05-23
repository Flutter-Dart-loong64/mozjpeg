/*
 * jdsample-lasx.c - upsampling (LoongArch LASX)
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
lasx_load16_u8(const JSAMPLE *p)
{
  uint8_t lane[32] = { 0 };

  memcpy(lane, p, 16);
  return __lasx_xvld(lane, 0);
}

void
jsimd_h2v1_upsample_lasx(int max_v_samp_factor, JDIMENSION output_width,
                         JSAMPARRAY input_data, JSAMPARRAY *output_data_ptr)
{
  JSAMPARRAY output_data = *output_data_ptr;
  int inrow;

  for (inrow = 0; inrow < max_v_samp_factor; inrow++) {
    JSAMPROW inptr = input_data[inrow];
    JSAMPROW outptr = output_data[inrow];
    JSAMPROW outend = outptr + output_width;

    while (outptr + 32 <= outend) {
      __m256i samples = lasx_load16_u8(inptr);
      __m256i expanded = __lasx_xvilvl_b(samples, samples);

      __lasx_xvst(expanded, outptr, 0);
      inptr += 16;
      outptr += 32;
    }

    while (outptr < outend) {
      JSAMPLE invalue = *inptr++;
      *outptr++ = invalue;
      if (outptr < outend)
        *outptr++ = invalue;
    }
  }
}

void
jsimd_h2v2_upsample_lasx(int max_v_samp_factor, JDIMENSION output_width,
                         JSAMPARRAY input_data, JSAMPARRAY *output_data_ptr)
{
  JSAMPARRAY output_data = *output_data_ptr;
  int inrow = 0, outrow = 0;

  while (outrow < max_v_samp_factor) {
    JSAMPROW inptr = input_data[inrow];
    JSAMPROW outptr = output_data[outrow];
    JSAMPROW outend = outptr + output_width;

    while (outptr + 32 <= outend) {
      __m256i samples = lasx_load16_u8(inptr);
      __m256i expanded = __lasx_xvilvl_b(samples, samples);

      __lasx_xvst(expanded, outptr, 0);
      inptr += 16;
      outptr += 32;
    }

    while (outptr < outend) {
      JSAMPLE invalue = *inptr++;
      *outptr++ = invalue;
      if (outptr < outend)
        *outptr++ = invalue;
    }

    jcopy_sample_rows(output_data, outrow, output_data, outrow + 1, 1,
                      output_width);
    inrow++;
    outrow += 2;
  }
}
