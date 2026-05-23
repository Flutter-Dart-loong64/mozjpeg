/*
 * jccolor-lsx.c - colorspace conversion (LoongArch LSX)
 *
 * Copyright (C) 2026, LoongArch Flutter/Dart port contributors.
 *
 * Based on the Arm Neon colorspace conversion code.
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

#define F_0_298  19595
#define F_0_587  38470
#define F_0_113   7471
#define F_0_168  11059
#define F_0_331  21709
#define F_0_500  32768
#define F_0_418  27439
#define F_0_081   5329
#define ONE_HALF  32768
#define CBCR_OFFSET_HALF  ((128 << 16) + 32767)

#define LOONGARCH_SIMD_LANES  8

static inline JSAMPLE
loongarch_y_from_rgb(int r, int g, int b)
{
  return (JSAMPLE)((F_0_298 * r + F_0_587 * g + F_0_113 * b + ONE_HALF) >>
                   16);
}

static inline JSAMPLE
loongarch_cb_from_rgb(int r, int g, int b)
{
  return (JSAMPLE)((-F_0_168 * r - F_0_331 * g + F_0_500 * b +
                    CBCR_OFFSET_HALF) >> 16);
}

static inline JSAMPLE
loongarch_cr_from_rgb(int r, int g, int b)
{
  return (JSAMPLE)((F_0_500 * r - F_0_418 * g - F_0_081 * b +
                    CBCR_OFFSET_HALF) >> 16);
}

static inline void
lsx_store4(JSAMPROW out, v4i32 v)
{
  int32_t t[4];

  memcpy(t, &v, sizeof(t));
  out[0] = (JSAMPLE)t[0];
  out[1] = (JSAMPLE)t[1];
  out[2] = (JSAMPLE)t[2];
  out[3] = (JSAMPLE)t[3];
}

static inline void
lsx_load4_rgb(const uint32_t *r, const uint32_t *g, const uint32_t *b,
              v4i32 *rv, v4i32 *gv, v4i32 *bv)
{
  memcpy(rv, r, sizeof(*rv));
  memcpy(gv, g, sizeof(*gv));
  memcpy(bv, b, sizeof(*bv));
}

static inline void
lsx_ycc4(const uint32_t *r, const uint32_t *g, const uint32_t *b,
         JSAMPROW yout, JSAMPROW cbout, JSAMPROW crout)
{
  v4i32 rv, gv, bv;
  v4i32 yv, cbv, crv;

  lsx_load4_rgb(r, g, b, &rv, &gv, &bv);

  yv = rv * F_0_298 + gv * F_0_587 + bv * F_0_113 + ONE_HALF;
  yv >>= 16;

  cbv = bv * F_0_500 - rv * F_0_168 - gv * F_0_331 + CBCR_OFFSET_HALF;
  cbv >>= 16;

  crv = rv * F_0_500 - gv * F_0_418 - bv * F_0_081 + CBCR_OFFSET_HALF;
  crv >>= 16;

  lsx_store4(yout, yv);
  lsx_store4(cbout, cbv);
  lsx_store4(crout, crv);
}

static inline void
loongarch_lsx_ycc_block(const uint32_t *r, const uint32_t *g,
                        const uint32_t *b, JSAMPROW yout, JSAMPROW cbout,
                        JSAMPROW crout)
{
  lsx_ycc4(r, g, b, yout, cbout, crout);
  lsx_ycc4(r + 4, g + 4, b + 4, yout + 4, cbout + 4, crout + 4);
}

static inline void
loongarch_lsx_gray_block(const uint32_t *r, const uint32_t *g,
                         const uint32_t *b, JSAMPROW yout)
{
  v4i32 rv, gv, bv, yv;

  lsx_load4_rgb(r, g, b, &rv, &gv, &bv);
  yv = rv * F_0_298 + gv * F_0_587 + bv * F_0_113 + ONE_HALF;
  yv >>= 16;
  lsx_store4(yout, yv);

  lsx_load4_rgb(r + 4, g + 4, b + 4, &rv, &gv, &bv);
  yv = rv * F_0_298 + gv * F_0_587 + bv * F_0_113 + ONE_HALF;
  yv >>= 16;
  lsx_store4(yout + 4, yv);
}

#define LOONGARCH_YCC_BLOCK  loongarch_lsx_ycc_block
#define LOONGARCH_GRAY_BLOCK loongarch_lsx_gray_block

#define JSIMD_RGB_YCC_CONVERT  jsimd_rgb_ycc_convert_lsx
#define JSIMD_RGB_GRAY_CONVERT jsimd_rgb_gray_convert_lsx
#include "jccolext-loongarch.c"
#undef JSIMD_RGB_YCC_CONVERT
#undef JSIMD_RGB_GRAY_CONVERT
#undef RGB_RED
#undef RGB_GREEN
#undef RGB_BLUE
#undef RGB_PIXELSIZE

#define RGB_RED  EXT_RGB_RED
#define RGB_GREEN  EXT_RGB_GREEN
#define RGB_BLUE  EXT_RGB_BLUE
#define RGB_PIXELSIZE  EXT_RGB_PIXELSIZE
#define JSIMD_RGB_YCC_CONVERT  jsimd_extrgb_ycc_convert_lsx
#define JSIMD_RGB_GRAY_CONVERT jsimd_extrgb_gray_convert_lsx
#include "jccolext-loongarch.c"
#undef JSIMD_RGB_YCC_CONVERT
#undef JSIMD_RGB_GRAY_CONVERT
#undef RGB_RED
#undef RGB_GREEN
#undef RGB_BLUE
#undef RGB_PIXELSIZE

#define RGB_RED  EXT_RGBX_RED
#define RGB_GREEN  EXT_RGBX_GREEN
#define RGB_BLUE  EXT_RGBX_BLUE
#define RGB_PIXELSIZE  EXT_RGBX_PIXELSIZE
#define JSIMD_RGB_YCC_CONVERT  jsimd_extrgbx_ycc_convert_lsx
#define JSIMD_RGB_GRAY_CONVERT jsimd_extrgbx_gray_convert_lsx
#include "jccolext-loongarch.c"
#undef JSIMD_RGB_YCC_CONVERT
#undef JSIMD_RGB_GRAY_CONVERT
#undef RGB_RED
#undef RGB_GREEN
#undef RGB_BLUE
#undef RGB_PIXELSIZE

#define RGB_RED  EXT_BGR_RED
#define RGB_GREEN  EXT_BGR_GREEN
#define RGB_BLUE  EXT_BGR_BLUE
#define RGB_PIXELSIZE  EXT_BGR_PIXELSIZE
#define JSIMD_RGB_YCC_CONVERT  jsimd_extbgr_ycc_convert_lsx
#define JSIMD_RGB_GRAY_CONVERT jsimd_extbgr_gray_convert_lsx
#include "jccolext-loongarch.c"
#undef JSIMD_RGB_YCC_CONVERT
#undef JSIMD_RGB_GRAY_CONVERT
#undef RGB_RED
#undef RGB_GREEN
#undef RGB_BLUE
#undef RGB_PIXELSIZE

#define RGB_RED  EXT_BGRX_RED
#define RGB_GREEN  EXT_BGRX_GREEN
#define RGB_BLUE  EXT_BGRX_BLUE
#define RGB_PIXELSIZE  EXT_BGRX_PIXELSIZE
#define JSIMD_RGB_YCC_CONVERT  jsimd_extbgrx_ycc_convert_lsx
#define JSIMD_RGB_GRAY_CONVERT jsimd_extbgrx_gray_convert_lsx
#include "jccolext-loongarch.c"
#undef JSIMD_RGB_YCC_CONVERT
#undef JSIMD_RGB_GRAY_CONVERT
#undef RGB_RED
#undef RGB_GREEN
#undef RGB_BLUE
#undef RGB_PIXELSIZE

#define RGB_RED  EXT_XBGR_RED
#define RGB_GREEN  EXT_XBGR_GREEN
#define RGB_BLUE  EXT_XBGR_BLUE
#define RGB_PIXELSIZE  EXT_XBGR_PIXELSIZE
#define JSIMD_RGB_YCC_CONVERT  jsimd_extxbgr_ycc_convert_lsx
#define JSIMD_RGB_GRAY_CONVERT jsimd_extxbgr_gray_convert_lsx
#include "jccolext-loongarch.c"
#undef JSIMD_RGB_YCC_CONVERT
#undef JSIMD_RGB_GRAY_CONVERT
#undef RGB_RED
#undef RGB_GREEN
#undef RGB_BLUE
#undef RGB_PIXELSIZE

#define RGB_RED  EXT_XRGB_RED
#define RGB_GREEN  EXT_XRGB_GREEN
#define RGB_BLUE  EXT_XRGB_BLUE
#define RGB_PIXELSIZE  EXT_XRGB_PIXELSIZE
#define JSIMD_RGB_YCC_CONVERT  jsimd_extxrgb_ycc_convert_lsx
#define JSIMD_RGB_GRAY_CONVERT jsimd_extxrgb_gray_convert_lsx
#include "jccolext-loongarch.c"
#undef JSIMD_RGB_YCC_CONVERT
#undef JSIMD_RGB_GRAY_CONVERT
#undef RGB_RED
#undef RGB_GREEN
#undef RGB_BLUE
#undef RGB_PIXELSIZE

#undef LOONGARCH_YCC_BLOCK
#undef LOONGARCH_GRAY_BLOCK
