/*
 * jdsample-lsx.c - upsampling (LoongArch LSX)
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
lsx_load8_u8(const JSAMPLE *p)
{
  uint64_t lane;

  memcpy(&lane, p, sizeof(lane));
  return __lsx_vldrepl_d(&lane, 0);
}

void
jsimd_h2v1_upsample_lsx(int max_v_samp_factor, JDIMENSION output_width,
                        JSAMPARRAY input_data, JSAMPARRAY *output_data_ptr)
{
  JSAMPARRAY output_data = *output_data_ptr;
  int inrow;

  for (inrow = 0; inrow < max_v_samp_factor; inrow++) {
    JSAMPROW inptr = input_data[inrow];
    JSAMPROW outptr = output_data[inrow];
    JSAMPROW outend = outptr + output_width;

    while (outptr + 16 <= outend) {
      __m128i samples = lsx_load8_u8(inptr);
      __m128i expanded = __lsx_vilvl_b(samples, samples);

      __lsx_vst(expanded, outptr, 0);
      inptr += 8;
      outptr += 16;
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
jsimd_h2v2_upsample_lsx(int max_v_samp_factor, JDIMENSION output_width,
                        JSAMPARRAY input_data, JSAMPARRAY *output_data_ptr)
{
  JSAMPARRAY output_data = *output_data_ptr;
  int inrow = 0, outrow = 0;

  while (outrow < max_v_samp_factor) {
    JSAMPROW inptr = input_data[inrow];
    JSAMPROW outptr = output_data[outrow];
    JSAMPROW outend = outptr + output_width;

    while (outptr + 16 <= outend) {
      __m128i samples = lsx_load8_u8(inptr);
      __m128i expanded = __lsx_vilvl_b(samples, samples);

      __lsx_vst(expanded, outptr, 0);
      inptr += 8;
      outptr += 16;
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
