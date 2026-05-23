/*
 * jdct-lsx.c - DCT sample conversion (LoongArch LSX)
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

void
jsimd_convsamp_lsx(JSAMPARRAY sample_data, JDIMENSION start_col,
                   DCTELEM *workspace)
{
  const __m128i zero = __lsx_vldi(0);
  const v8i16 center = {
    CENTERJSAMPLE, CENTERJSAMPLE, CENTERJSAMPLE, CENTERJSAMPLE,
    CENTERJSAMPLE, CENTERJSAMPLE, CENTERJSAMPLE, CENTERJSAMPLE
  };
  int elemr;

  for (elemr = 0; elemr < DCTSIZE; elemr++) {
    uint64_t lane;
    __m128i samples, widened;

    memcpy(&lane, sample_data[elemr] + start_col, sizeof(lane));
    samples = __lsx_vldrepl_d(&lane, 0);
    widened = __lsx_vilvl_b(zero, samples);
    widened = __lsx_vsub_h(widened, (__m128i)center);
    __lsx_vst(widened, workspace + elemr * DCTSIZE, 0);
  }
}
