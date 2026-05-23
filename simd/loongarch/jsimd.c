/*
 * jsimd_loongarch.c
 *
 * Copyright (C) 2026, LoongArch Flutter/Dart port contributors.
 *
 * Based on the PowerPC and MIPS SIMD interface code.
 * For conditions of distribution and use, see copyright notice in jsimdext.inc.
 *
 * This file contains the interface between the generic library code and the
 * LoongArch LSX/LASX implementations.  Only the functions whose jsimd_can_*()
 * predicates return 1 are provided by this backend; the remaining entry
 * points are stubs from jsimd_none_loongarch.c.
 */

#define jsimd_can_h2v2_downsample jsimd_can_h2v2_downsample_none
#define jsimd_can_h2v1_downsample jsimd_can_h2v1_downsample_none
#define jsimd_can_h2v2_smooth_downsample \
  jsimd_can_h2v2_smooth_downsample_none
#define jsimd_h2v2_downsample jsimd_h2v2_downsample_none
#define jsimd_h2v2_smooth_downsample jsimd_h2v2_smooth_downsample_none
#define jsimd_h2v1_downsample jsimd_h2v1_downsample_none
#define jsimd_can_h2v2_upsample jsimd_can_h2v2_upsample_none
#define jsimd_can_h2v1_upsample jsimd_can_h2v1_upsample_none
#define jsimd_can_int_upsample jsimd_can_int_upsample_none
#define jsimd_int_upsample jsimd_int_upsample_none
#define jsimd_h2v2_upsample jsimd_h2v2_upsample_none
#define jsimd_h2v1_upsample jsimd_h2v1_upsample_none
#define jsimd_can_h2v2_fancy_upsample \
  jsimd_can_h2v2_fancy_upsample_none
#define jsimd_can_h2v1_fancy_upsample \
  jsimd_can_h2v1_fancy_upsample_none
#define jsimd_can_h1v2_fancy_upsample \
  jsimd_can_h1v2_fancy_upsample_none
#define jsimd_h2v2_fancy_upsample jsimd_h2v2_fancy_upsample_none
#define jsimd_h2v1_fancy_upsample jsimd_h2v1_fancy_upsample_none
#define jsimd_h1v2_fancy_upsample jsimd_h1v2_fancy_upsample_none
#define jsimd_can_convsamp jsimd_can_convsamp_none
#define jsimd_can_convsamp_float jsimd_can_convsamp_float_none
#define jsimd_convsamp jsimd_convsamp_none
#define jsimd_convsamp_float jsimd_convsamp_float_none
#define jsimd_can_fdct_islow jsimd_can_fdct_islow_none
#define jsimd_can_fdct_ifast jsimd_can_fdct_ifast_none
#define jsimd_can_fdct_float jsimd_can_fdct_float_none
#define jsimd_fdct_islow jsimd_fdct_islow_none
#define jsimd_fdct_ifast jsimd_fdct_ifast_none
#define jsimd_fdct_float jsimd_fdct_float_none
#define jsimd_can_quantize jsimd_can_quantize_none
#define jsimd_can_quantize_float jsimd_can_quantize_float_none
#define jsimd_quantize jsimd_quantize_none
#define jsimd_quantize_float jsimd_quantize_float_none
#define jsimd_can_idct_2x2 jsimd_can_idct_2x2_none
#define jsimd_can_idct_4x4 jsimd_can_idct_4x4_none
#define jsimd_can_idct_6x6 jsimd_can_idct_6x6_none
#define jsimd_can_idct_12x12 jsimd_can_idct_12x12_none
#define jsimd_idct_2x2 jsimd_idct_2x2_none
#define jsimd_idct_4x4 jsimd_idct_4x4_none
#define jsimd_idct_6x6 jsimd_idct_6x6_none
#define jsimd_idct_12x12 jsimd_idct_12x12_none
#define jsimd_can_idct_islow jsimd_can_idct_islow_none
#define jsimd_can_idct_ifast jsimd_can_idct_ifast_none
#define jsimd_can_idct_float jsimd_can_idct_float_none
#define jsimd_idct_islow jsimd_idct_islow_none
#define jsimd_idct_ifast jsimd_idct_ifast_none
#define jsimd_idct_float jsimd_idct_float_none
#define jsimd_can_huff_encode_one_block \
  jsimd_can_huff_encode_one_block_none
#define jsimd_huff_encode_one_block jsimd_huff_encode_one_block_none
#define jsimd_can_encode_mcu_AC_first_prepare \
  jsimd_can_encode_mcu_AC_first_prepare_none
#define jsimd_encode_mcu_AC_first_prepare \
  jsimd_encode_mcu_AC_first_prepare_none
#define jsimd_can_encode_mcu_AC_refine_prepare \
  jsimd_can_encode_mcu_AC_refine_prepare_none
#define jsimd_encode_mcu_AC_refine_prepare \
  jsimd_encode_mcu_AC_refine_prepare_none
#define jsimd_can_rgb_ycc jsimd_can_rgb_ycc_none
#define jsimd_can_rgb_gray jsimd_can_rgb_gray_none
#define jsimd_rgb_ycc_convert jsimd_rgb_ycc_convert_none
#define jsimd_rgb_gray_convert jsimd_rgb_gray_convert_none
#include "jsimd_none_loongarch.c"
#undef jsimd_can_h2v2_downsample
#undef jsimd_can_h2v1_downsample
#undef jsimd_can_h2v2_smooth_downsample
#undef jsimd_h2v2_downsample
#undef jsimd_h2v2_smooth_downsample
#undef jsimd_h2v1_downsample
#undef jsimd_can_h2v2_upsample
#undef jsimd_can_h2v1_upsample
#undef jsimd_can_int_upsample
#undef jsimd_int_upsample
#undef jsimd_h2v2_upsample
#undef jsimd_h2v1_upsample
#undef jsimd_can_h2v2_fancy_upsample
#undef jsimd_can_h2v1_fancy_upsample
#undef jsimd_can_h1v2_fancy_upsample
#undef jsimd_h2v2_fancy_upsample
#undef jsimd_h2v1_fancy_upsample
#undef jsimd_h1v2_fancy_upsample
#undef jsimd_can_convsamp
#undef jsimd_can_convsamp_float
#undef jsimd_convsamp
#undef jsimd_convsamp_float
#undef jsimd_can_fdct_islow
#undef jsimd_can_fdct_ifast
#undef jsimd_can_fdct_float
#undef jsimd_fdct_islow
#undef jsimd_fdct_ifast
#undef jsimd_fdct_float
#undef jsimd_can_quantize
#undef jsimd_can_quantize_float
#undef jsimd_quantize
#undef jsimd_quantize_float
#undef jsimd_can_idct_2x2
#undef jsimd_can_idct_4x4
#undef jsimd_can_idct_6x6
#undef jsimd_can_idct_12x12
#undef jsimd_idct_2x2
#undef jsimd_idct_4x4
#undef jsimd_idct_6x6
#undef jsimd_idct_12x12
#undef jsimd_can_idct_islow
#undef jsimd_can_idct_ifast
#undef jsimd_can_idct_float
#undef jsimd_idct_islow
#undef jsimd_idct_ifast
#undef jsimd_idct_float
#undef jsimd_can_huff_encode_one_block
#undef jsimd_huff_encode_one_block
#undef jsimd_can_encode_mcu_AC_first_prepare
#undef jsimd_encode_mcu_AC_first_prepare
#undef jsimd_can_encode_mcu_AC_refine_prepare
#undef jsimd_encode_mcu_AC_refine_prepare
#undef jsimd_can_rgb_ycc
#undef jsimd_can_rgb_gray
#undef jsimd_rgb_ycc_convert
#undef jsimd_rgb_gray_convert

#include "../jsimd.h"
#include "jsimd_loongarch.h"
#include "../../jdsample.h"

#include <ctype.h>
#include <limits.h>

#if defined(__linux__)
#include <sys/auxv.h>
#include <asm/hwcap.h>
#endif

#ifndef HWCAP_LOONGARCH_LSX
#define HWCAP_LOONGARCH_LSX   (1UL << 4)
#endif

#ifndef HWCAP_LOONGARCH_LASX
#define HWCAP_LOONGARCH_LASX  (1UL << 5)
#endif

static THREAD_LOCAL unsigned int simd_support = ~0U;

#if defined(__linux__)
#define SOMEWHAT_SANE_PROC_CPUINFO_SIZE_LIMIT  (1024 * 1024)

LOCAL(int)
check_feature(char *buffer, const char *feature)
{
  char *p;

  if (*feature == 0)
    return 0;
  if (strncmp(buffer, "Features", 8) != 0)
    return 0;
  buffer += 8;
  while (isspace((unsigned char)*buffer) || *buffer == ':')
    buffer++;

  while ((p = strstr(buffer, feature))) {
    if (p > buffer && !isspace((unsigned char)*(p - 1))) {
      buffer++;
      continue;
    }
    p += strlen(feature);
    if (*p != 0 && !isspace((unsigned char)*p)) {
      buffer++;
      continue;
    }
    return 1;
  }
  return 0;
}

LOCAL(int)
parse_proc_cpuinfo(int bufsize)
{
  char *buffer = (char *)malloc(bufsize);
  FILE *fd;

  if (!buffer)
    return 0;

  fd = fopen("/proc/cpuinfo", "r");
  if (fd) {
    while (fgets(buffer, bufsize, fd)) {
      if (!strchr(buffer, '\n') && !feof(fd)) {
        fclose(fd);
        free(buffer);
        return 0;
      }
      if (check_feature(buffer, "lsx"))
        simd_support |= JSIMD_LSX;
      if (check_feature(buffer, "lasx"))
        simd_support |= JSIMD_LASX | JSIMD_LSX;
    }
    fclose(fd);
  }
  free(buffer);
  return 1;
}
#endif

LOCAL(void)
init_simd(void)
{
#ifndef NO_GETENV
  char *env = NULL;
#endif
#if defined(__linux__)
  int bufsize = 1024;
  unsigned long hwcap;
#endif

  if (simd_support != ~0U)
    return;

  simd_support = 0;

#if defined(__linux__)
  hwcap = getauxval(AT_HWCAP);
  if (hwcap & HWCAP_LOONGARCH_LSX)
    simd_support |= JSIMD_LSX;
  if (hwcap & HWCAP_LOONGARCH_LASX)
    simd_support |= JSIMD_LASX | JSIMD_LSX;

  if (simd_support == 0) {
    while (!parse_proc_cpuinfo(bufsize)) {
      bufsize *= 2;
      if (bufsize > SOMEWHAT_SANE_PROC_CPUINFO_SIZE_LIMIT)
        break;
    }
  }
#endif

#ifndef NO_GETENV
  env = getenv("JSIMD_FORCELASX");
  if ((env != NULL) && (strcmp(env, "1") == 0))
    simd_support = JSIMD_LASX | JSIMD_LSX;
  env = getenv("JSIMD_FORCELSX");
  if ((env != NULL) && (strcmp(env, "1") == 0))
    simd_support = JSIMD_LSX;
  env = getenv("JSIMD_FORCENONE");
  if ((env != NULL) && (strcmp(env, "1") == 0))
    simd_support = 0;
#endif
}

LOCAL(int)
loongarch_has_lsx(void)
{
  init_simd();
  return (simd_support & JSIMD_LSX) != 0;
}

GLOBAL(int)
jsimd_can_rgb_ycc(void)
{
  init_simd();

  if (BITS_IN_JSAMPLE != 8)
    return 0;
  if (sizeof(JDIMENSION) != 4)
    return 0;
  if ((RGB_PIXELSIZE != 3) && (RGB_PIXELSIZE != 4))
    return 0;

  if (simd_support & JSIMD_LSX)
    return 1;

  return 0;
}

GLOBAL(int)
jsimd_can_rgb_gray(void)
{
  init_simd();

  if (BITS_IN_JSAMPLE != 8)
    return 0;
  if (sizeof(JDIMENSION) != 4)
    return 0;
  if ((RGB_PIXELSIZE != 3) && (RGB_PIXELSIZE != 4))
    return 0;

  if (simd_support & JSIMD_LSX)
    return 1;

  return 0;
}

GLOBAL(void)
jsimd_rgb_ycc_convert(j_compress_ptr cinfo, JSAMPARRAY input_buf,
                      JSAMPIMAGE output_buf, JDIMENSION output_row,
                      int num_rows)
{
  void (*lsxflt) (JDIMENSION, JSAMPARRAY, JSAMPIMAGE, JDIMENSION, int);
#if defined(JSIMD_LOONGARCH_LASX)
  void (*lasxflt) (JDIMENSION, JSAMPARRAY, JSAMPIMAGE, JDIMENSION, int);
#endif

  switch (cinfo->in_color_space) {
  case JCS_EXT_RGB:
    lsxflt = jsimd_extrgb_ycc_convert_lsx;
#if defined(JSIMD_LOONGARCH_LASX)
    lasxflt = jsimd_extrgb_ycc_convert_lasx;
#endif
    break;
  case JCS_EXT_RGBX:
  case JCS_EXT_RGBA:
    lsxflt = jsimd_extrgbx_ycc_convert_lsx;
#if defined(JSIMD_LOONGARCH_LASX)
    lasxflt = jsimd_extrgbx_ycc_convert_lasx;
#endif
    break;
  case JCS_EXT_BGR:
    lsxflt = jsimd_extbgr_ycc_convert_lsx;
#if defined(JSIMD_LOONGARCH_LASX)
    lasxflt = jsimd_extbgr_ycc_convert_lasx;
#endif
    break;
  case JCS_EXT_BGRX:
  case JCS_EXT_BGRA:
    lsxflt = jsimd_extbgrx_ycc_convert_lsx;
#if defined(JSIMD_LOONGARCH_LASX)
    lasxflt = jsimd_extbgrx_ycc_convert_lasx;
#endif
    break;
  case JCS_EXT_XBGR:
  case JCS_EXT_ABGR:
    lsxflt = jsimd_extxbgr_ycc_convert_lsx;
#if defined(JSIMD_LOONGARCH_LASX)
    lasxflt = jsimd_extxbgr_ycc_convert_lasx;
#endif
    break;
  case JCS_EXT_XRGB:
  case JCS_EXT_ARGB:
    lsxflt = jsimd_extxrgb_ycc_convert_lsx;
#if defined(JSIMD_LOONGARCH_LASX)
    lasxflt = jsimd_extxrgb_ycc_convert_lasx;
#endif
    break;
  default:
    lsxflt = jsimd_rgb_ycc_convert_lsx;
#if defined(JSIMD_LOONGARCH_LASX)
    lasxflt = jsimd_rgb_ycc_convert_lasx;
#endif
    break;
  }

#if defined(JSIMD_LOONGARCH_LASX)
  if (simd_support & JSIMD_LASX) {
    lasxflt(cinfo->image_width, input_buf, output_buf, output_row, num_rows);
    return;
  }
#endif

  lsxflt(cinfo->image_width, input_buf, output_buf, output_row, num_rows);
}

GLOBAL(void)
jsimd_rgb_gray_convert(j_compress_ptr cinfo, JSAMPARRAY input_buf,
                       JSAMPIMAGE output_buf, JDIMENSION output_row,
                       int num_rows)
{
  void (*lsxflt) (JDIMENSION, JSAMPARRAY, JSAMPIMAGE, JDIMENSION, int);
#if defined(JSIMD_LOONGARCH_LASX)
  void (*lasxflt) (JDIMENSION, JSAMPARRAY, JSAMPIMAGE, JDIMENSION, int);
#endif

  switch (cinfo->in_color_space) {
  case JCS_EXT_RGB:
    lsxflt = jsimd_extrgb_gray_convert_lsx;
#if defined(JSIMD_LOONGARCH_LASX)
    lasxflt = jsimd_extrgb_gray_convert_lasx;
#endif
    break;
  case JCS_EXT_RGBX:
  case JCS_EXT_RGBA:
    lsxflt = jsimd_extrgbx_gray_convert_lsx;
#if defined(JSIMD_LOONGARCH_LASX)
    lasxflt = jsimd_extrgbx_gray_convert_lasx;
#endif
    break;
  case JCS_EXT_BGR:
    lsxflt = jsimd_extbgr_gray_convert_lsx;
#if defined(JSIMD_LOONGARCH_LASX)
    lasxflt = jsimd_extbgr_gray_convert_lasx;
#endif
    break;
  case JCS_EXT_BGRX:
  case JCS_EXT_BGRA:
    lsxflt = jsimd_extbgrx_gray_convert_lsx;
#if defined(JSIMD_LOONGARCH_LASX)
    lasxflt = jsimd_extbgrx_gray_convert_lasx;
#endif
    break;
  case JCS_EXT_XBGR:
  case JCS_EXT_ABGR:
    lsxflt = jsimd_extxbgr_gray_convert_lsx;
#if defined(JSIMD_LOONGARCH_LASX)
    lasxflt = jsimd_extxbgr_gray_convert_lasx;
#endif
    break;
  case JCS_EXT_XRGB:
  case JCS_EXT_ARGB:
    lsxflt = jsimd_extxrgb_gray_convert_lsx;
#if defined(JSIMD_LOONGARCH_LASX)
    lasxflt = jsimd_extxrgb_gray_convert_lasx;
#endif
    break;
  default:
    lsxflt = jsimd_rgb_gray_convert_lsx;
#if defined(JSIMD_LOONGARCH_LASX)
    lasxflt = jsimd_rgb_gray_convert_lasx;
#endif
    break;
  }

#if defined(JSIMD_LOONGARCH_LASX)
  if (simd_support & JSIMD_LASX) {
    lasxflt(cinfo->image_width, input_buf, output_buf, output_row, num_rows);
    return;
  }
#endif

  lsxflt(cinfo->image_width, input_buf, output_buf, output_row, num_rows);
}

GLOBAL(int)
jsimd_can_h2v2_downsample(void)
{
  if (BITS_IN_JSAMPLE != 8)
    return 0;
  if (DCTSIZE != 8)
    return 0;
  if (sizeof(JDIMENSION) != 4)
    return 0;

  return loongarch_has_lsx();
}

GLOBAL(int)
jsimd_can_h2v1_downsample(void)
{
  if (BITS_IN_JSAMPLE != 8)
    return 0;
  if (DCTSIZE != 8)
    return 0;
  if (sizeof(JDIMENSION) != 4)
    return 0;

  return loongarch_has_lsx();
}

GLOBAL(int)
jsimd_can_h2v2_smooth_downsample(void)
{
  if (BITS_IN_JSAMPLE != 8)
    return 0;
  if (DCTSIZE != 8)
    return 0;
  if (sizeof(JDIMENSION) != 4)
    return 0;

  return loongarch_has_lsx();
}

LOCAL(void)
loongarch_expand_right_edge(JSAMPARRAY image_data, int num_rows,
                            JDIMENSION input_cols, JDIMENSION output_cols)
{
  JSAMPROW ptr;
  JSAMPLE pixval;
  int count, row;
  int numcols = (int)(output_cols - input_cols);

  if (numcols > 0) {
    for (row = 0; row < num_rows; row++) {
      ptr = image_data[row] + input_cols;
      pixval = ptr[-1];
      for (count = numcols; count > 0; count--)
        *ptr++ = pixval;
    }
  }
}

GLOBAL(void)
jsimd_h2v1_downsample(j_compress_ptr cinfo, jpeg_component_info *compptr,
                      JSAMPARRAY input_data, JSAMPARRAY output_data)
{
  JDIMENSION output_cols = compptr->width_in_blocks * DCTSIZE;

  loongarch_expand_right_edge(input_data, cinfo->max_v_samp_factor,
                              cinfo->image_width, output_cols * 2);

#if defined(JSIMD_LOONGARCH_LASX)
  if (simd_support & JSIMD_LASX) {
    jsimd_h2v1_downsample_lasx(compptr->width_in_blocks,
                               compptr->v_samp_factor, input_data,
                               output_data);
    return;
  }
#endif

  jsimd_h2v1_downsample_lsx(compptr->width_in_blocks, compptr->v_samp_factor,
                            input_data, output_data);
}

GLOBAL(void)
jsimd_h2v2_downsample(j_compress_ptr cinfo, jpeg_component_info *compptr,
                      JSAMPARRAY input_data, JSAMPARRAY output_data)
{
  JDIMENSION output_cols = compptr->width_in_blocks * DCTSIZE;

  loongarch_expand_right_edge(input_data, cinfo->max_v_samp_factor,
                              cinfo->image_width, output_cols * 2);

#if defined(JSIMD_LOONGARCH_LASX)
  if (simd_support & JSIMD_LASX) {
    jsimd_h2v2_downsample_lasx(compptr->width_in_blocks,
                               compptr->v_samp_factor, input_data,
                               output_data);
    return;
  }
#endif

  jsimd_h2v2_downsample_lsx(compptr->width_in_blocks, compptr->v_samp_factor,
                            input_data, output_data);
}

GLOBAL(void)
jsimd_h2v2_smooth_downsample(j_compress_ptr cinfo,
                             jpeg_component_info *compptr,
                             JSAMPARRAY input_data, JSAMPARRAY output_data)
{
  int inrow, outrow;
  JDIMENSION colctr;
  JDIMENSION output_cols = compptr->width_in_blocks * DCTSIZE;
  JSAMPROW inptr0, inptr1, above_ptr, below_ptr, outptr;
  JLONG membersum, neighsum, memberscale, neighscale;

  loongarch_expand_right_edge(input_data - 1, cinfo->max_v_samp_factor + 2,
                              cinfo->image_width, output_cols * 2);

  memberscale = 16384 - cinfo->smoothing_factor * 80;
  neighscale = cinfo->smoothing_factor * 16;

  inrow = 0;
  for (outrow = 0; outrow < compptr->v_samp_factor; outrow++) {
    outptr = output_data[outrow];
    inptr0 = input_data[inrow];
    inptr1 = input_data[inrow + 1];
    above_ptr = input_data[inrow - 1];
    below_ptr = input_data[inrow + 2];

    membersum = inptr0[0] + inptr0[1] + inptr1[0] + inptr1[1];
    neighsum = above_ptr[0] + above_ptr[1] + below_ptr[0] + below_ptr[1] +
               inptr0[0] + inptr0[2] + inptr1[0] + inptr1[2];
    neighsum += neighsum;
    neighsum += above_ptr[0] + above_ptr[2] + below_ptr[0] + below_ptr[2];
    membersum = membersum * memberscale + neighsum * neighscale;
    *outptr++ = (JSAMPLE)((membersum + 32768) >> 16);
    inptr0 += 2;
    inptr1 += 2;
    above_ptr += 2;
    below_ptr += 2;

    for (colctr = output_cols - 2; colctr > 0; colctr--) {
      membersum = inptr0[0] + inptr0[1] + inptr1[0] + inptr1[1];
      neighsum = above_ptr[0] + above_ptr[1] + below_ptr[0] + below_ptr[1] +
                 inptr0[-1] + inptr0[2] + inptr1[-1] + inptr1[2];
      neighsum += neighsum;
      neighsum += above_ptr[-1] + above_ptr[2] + below_ptr[-1] + below_ptr[2];
      membersum = membersum * memberscale + neighsum * neighscale;
      *outptr++ = (JSAMPLE)((membersum + 32768) >> 16);
      inptr0 += 2;
      inptr1 += 2;
      above_ptr += 2;
      below_ptr += 2;
    }

    membersum = inptr0[0] + inptr0[1] + inptr1[0] + inptr1[1];
    neighsum = above_ptr[0] + above_ptr[1] + below_ptr[0] + below_ptr[1] +
               inptr0[-1] + inptr0[1] + inptr1[-1] + inptr1[1];
    neighsum += neighsum;
    neighsum += above_ptr[-1] + above_ptr[1] + below_ptr[-1] + below_ptr[1];
    membersum = membersum * memberscale + neighsum * neighscale;
    *outptr = (JSAMPLE)((membersum + 32768) >> 16);

    inrow += 2;
  }
}

GLOBAL(int)
jsimd_can_h2v2_upsample(void)
{
  if (BITS_IN_JSAMPLE != 8)
    return 0;
  if (sizeof(JDIMENSION) != 4)
    return 0;

  return loongarch_has_lsx();
}

GLOBAL(int)
jsimd_can_h2v1_upsample(void)
{
  if (BITS_IN_JSAMPLE != 8)
    return 0;
  if (sizeof(JDIMENSION) != 4)
    return 0;

  return loongarch_has_lsx();
}

GLOBAL(int)
jsimd_can_int_upsample(void)
{
  if (BITS_IN_JSAMPLE != 8)
    return 0;
  if (sizeof(JDIMENSION) != 4)
    return 0;

  return loongarch_has_lsx();
}

GLOBAL(void)
jsimd_int_upsample(j_decompress_ptr cinfo, jpeg_component_info *compptr,
                   JSAMPARRAY input_data, JSAMPARRAY *output_data_ptr)
{
  my_upsample_ptr upsample = (my_upsample_ptr)cinfo->upsample;
  JSAMPARRAY output_data = *output_data_ptr;
  JSAMPROW inptr, outptr, outend;
  JSAMPLE invalue;
  int h, h_expand, v_expand, inrow, outrow;

  h_expand = upsample->h_expand[compptr->component_index];
  v_expand = upsample->v_expand[compptr->component_index];

  inrow = outrow = 0;
  while (outrow < cinfo->max_v_samp_factor) {
    inptr = input_data[inrow];
    outptr = output_data[outrow];
    outend = outptr + cinfo->output_width;
    while (outptr < outend) {
      invalue = *inptr++;
      for (h = h_expand; h > 0; h--)
        *outptr++ = invalue;
    }
    if (v_expand > 1) {
      jcopy_sample_rows(output_data, outrow, output_data, outrow + 1,
                        v_expand - 1, cinfo->output_width);
    }
    inrow++;
    outrow += v_expand;
  }
}

GLOBAL(void)
jsimd_h2v1_upsample(j_decompress_ptr cinfo, jpeg_component_info *compptr,
                    JSAMPARRAY input_data, JSAMPARRAY *output_data_ptr)
{
  (void)compptr;

#if defined(JSIMD_LOONGARCH_LASX)
  if (simd_support & JSIMD_LASX) {
    jsimd_h2v1_upsample_lasx(cinfo->max_v_samp_factor, cinfo->output_width,
                             input_data, output_data_ptr);
    return;
  }
#endif

  jsimd_h2v1_upsample_lsx(cinfo->max_v_samp_factor, cinfo->output_width,
                          input_data, output_data_ptr);
}

GLOBAL(void)
jsimd_h2v2_upsample(j_decompress_ptr cinfo, jpeg_component_info *compptr,
                    JSAMPARRAY input_data, JSAMPARRAY *output_data_ptr)
{
  (void)compptr;

#if defined(JSIMD_LOONGARCH_LASX)
  if (simd_support & JSIMD_LASX) {
    jsimd_h2v2_upsample_lasx(cinfo->max_v_samp_factor, cinfo->output_width,
                             input_data, output_data_ptr);
    return;
  }
#endif

  jsimd_h2v2_upsample_lsx(cinfo->max_v_samp_factor, cinfo->output_width,
                          input_data, output_data_ptr);
}

GLOBAL(int)
jsimd_can_h2v2_fancy_upsample(void)
{
  if (BITS_IN_JSAMPLE != 8)
    return 0;
  if (sizeof(JDIMENSION) != 4)
    return 0;

  return loongarch_has_lsx();
}

GLOBAL(int)
jsimd_can_h2v1_fancy_upsample(void)
{
  if (BITS_IN_JSAMPLE != 8)
    return 0;
  if (sizeof(JDIMENSION) != 4)
    return 0;

  return loongarch_has_lsx();
}

GLOBAL(int)
jsimd_can_h1v2_fancy_upsample(void)
{
  if (BITS_IN_JSAMPLE != 8)
    return 0;
  if (sizeof(JDIMENSION) != 4)
    return 0;

  return loongarch_has_lsx();
}

GLOBAL(void)
jsimd_h2v1_fancy_upsample(j_decompress_ptr cinfo,
                          jpeg_component_info *compptr,
                          JSAMPARRAY input_data,
                          JSAMPARRAY *output_data_ptr)
{
  JSAMPARRAY output_data = *output_data_ptr;
  JSAMPROW inptr, outptr;
  int invalue;
  JDIMENSION colctr;
  int inrow;

  for (inrow = 0; inrow < cinfo->max_v_samp_factor; inrow++) {
    inptr = input_data[inrow];
    outptr = output_data[inrow];
    invalue = *inptr++;
    *outptr++ = (JSAMPLE)invalue;
    *outptr++ = (JSAMPLE)((invalue * 3 + inptr[0] + 2) >> 2);

    for (colctr = compptr->downsampled_width - 2; colctr > 0; colctr--) {
      invalue = (*inptr++) * 3;
      *outptr++ = (JSAMPLE)((invalue + inptr[-2] + 1) >> 2);
      *outptr++ = (JSAMPLE)((invalue + inptr[0] + 2) >> 2);
    }

    invalue = *inptr;
    *outptr++ = (JSAMPLE)((invalue * 3 + inptr[-1] + 1) >> 2);
    *outptr++ = (JSAMPLE)invalue;
  }
}

GLOBAL(void)
jsimd_h1v2_fancy_upsample(j_decompress_ptr cinfo,
                          jpeg_component_info *compptr,
                          JSAMPARRAY input_data,
                          JSAMPARRAY *output_data_ptr)
{
  JSAMPARRAY output_data = *output_data_ptr;
  JSAMPROW inptr0, inptr1, outptr;
  int thiscolsum, bias;
  JDIMENSION colctr;
  int inrow, outrow, v;

  inrow = outrow = 0;
  while (outrow < cinfo->max_v_samp_factor) {
    for (v = 0; v < 2; v++) {
      inptr0 = input_data[inrow];
      if (v == 0) {
        inptr1 = input_data[inrow - 1];
        bias = 1;
      } else {
        inptr1 = input_data[inrow + 1];
        bias = 2;
      }
      outptr = output_data[outrow++];

      for (colctr = 0; colctr < compptr->downsampled_width; colctr++) {
        thiscolsum = (*inptr0++) * 3 + (*inptr1++);
        *outptr++ = (JSAMPLE)((thiscolsum + bias) >> 2);
      }
    }
    inrow++;
  }
}

GLOBAL(void)
jsimd_h2v2_fancy_upsample(j_decompress_ptr cinfo,
                          jpeg_component_info *compptr,
                          JSAMPARRAY input_data,
                          JSAMPARRAY *output_data_ptr)
{
  JSAMPARRAY output_data = *output_data_ptr;
  JSAMPROW inptr0, inptr1, outptr;
  int thiscolsum, lastcolsum, nextcolsum;
  JDIMENSION colctr;
  int inrow, outrow, v;

  inrow = outrow = 0;
  while (outrow < cinfo->max_v_samp_factor) {
    for (v = 0; v < 2; v++) {
      inptr0 = input_data[inrow];
      if (v == 0)
        inptr1 = input_data[inrow - 1];
      else
        inptr1 = input_data[inrow + 1];
      outptr = output_data[outrow++];

      thiscolsum = (*inptr0++) * 3 + (*inptr1++);
      nextcolsum = (*inptr0++) * 3 + (*inptr1++);
      *outptr++ = (JSAMPLE)((thiscolsum * 4 + 8) >> 4);
      *outptr++ = (JSAMPLE)((thiscolsum * 3 + nextcolsum + 7) >> 4);
      lastcolsum = thiscolsum;
      thiscolsum = nextcolsum;

      for (colctr = compptr->downsampled_width - 2; colctr > 0; colctr--) {
        nextcolsum = (*inptr0++) * 3 + (*inptr1++);
        *outptr++ = (JSAMPLE)((thiscolsum * 3 + lastcolsum + 8) >> 4);
        *outptr++ = (JSAMPLE)((thiscolsum * 3 + nextcolsum + 7) >> 4);
        lastcolsum = thiscolsum;
        thiscolsum = nextcolsum;
      }

      *outptr++ = (JSAMPLE)((thiscolsum * 3 + lastcolsum + 8) >> 4);
      *outptr++ = (JSAMPLE)((thiscolsum * 4 + 7) >> 4);
    }
    inrow++;
  }
}

GLOBAL(int)
jsimd_can_convsamp(void)
{
  if (DCTSIZE != 8)
    return 0;
  if (BITS_IN_JSAMPLE != 8)
    return 0;
  if (sizeof(JDIMENSION) != 4)
    return 0;
  if (sizeof(DCTELEM) != 2)
    return 0;

  return loongarch_has_lsx();
}

GLOBAL(int)
jsimd_can_convsamp_float(void)
{
  if (DCTSIZE != 8)
    return 0;
  if (BITS_IN_JSAMPLE != 8)
    return 0;
  if (sizeof(JDIMENSION) != 4)
    return 0;

  return loongarch_has_lsx();
}

GLOBAL(void)
jsimd_convsamp(JSAMPARRAY sample_data, JDIMENSION start_col,
               DCTELEM *workspace)
{
  jsimd_convsamp_lsx(sample_data, start_col, workspace);
}

GLOBAL(void)
jsimd_convsamp_float(JSAMPARRAY sample_data, JDIMENSION start_col,
                     FAST_FLOAT *workspace)
{
  FAST_FLOAT *workspaceptr = workspace;
  JSAMPROW elemptr;
  int elemr, elemc;

  for (elemr = 0; elemr < DCTSIZE; elemr++) {
    elemptr = sample_data[elemr] + start_col;
    for (elemc = DCTSIZE; elemc > 0; elemc--)
      *workspaceptr++ = (FAST_FLOAT)((*elemptr++) - CENTERJSAMPLE);
  }
}

GLOBAL(int)
jsimd_can_fdct_islow(void)
{
  if (DCTSIZE != 8)
    return 0;
  if (sizeof(DCTELEM) != 2)
    return 0;

  return loongarch_has_lsx();
}

GLOBAL(int)
jsimd_can_fdct_ifast(void)
{
  if (DCTSIZE != 8)
    return 0;
  if (sizeof(DCTELEM) != 2)
    return 0;

  return loongarch_has_lsx();
}

GLOBAL(int)
jsimd_can_fdct_float(void)
{
  if (DCTSIZE != 8)
    return 0;

  return loongarch_has_lsx();
}

GLOBAL(void)
jsimd_fdct_islow(DCTELEM *data)
{
  jpeg_fdct_islow(data);
}

GLOBAL(void)
jsimd_fdct_ifast(DCTELEM *data)
{
  jpeg_fdct_ifast(data);
}

GLOBAL(void)
jsimd_fdct_float(FAST_FLOAT *data)
{
  jpeg_fdct_float(data);
}

GLOBAL(int)
jsimd_can_quantize(void)
{
  if (DCTSIZE != 8)
    return 0;
  if (sizeof(JCOEF) != 2)
    return 0;
  if (sizeof(DCTELEM) != 2)
    return 0;

  return loongarch_has_lsx();
}

GLOBAL(int)
jsimd_can_quantize_float(void)
{
  if (DCTSIZE != 8)
    return 0;
  if (sizeof(JCOEF) != 2)
    return 0;

  return loongarch_has_lsx();
}

GLOBAL(void)
jsimd_quantize(JCOEFPTR coef_block, DCTELEM *divisors, DCTELEM *workspace)
{
  int i;
  DCTELEM temp;
  JCOEFPTR output_ptr = coef_block;

#if BITS_IN_JSAMPLE == 8
  UDCTELEM recip, corr;
  int shift;
  UDCTELEM2 product;

  for (i = 0; i < DCTSIZE2; i++) {
    temp = workspace[i];
    recip = divisors[i + DCTSIZE2 * 0];
    corr = divisors[i + DCTSIZE2 * 1];
    shift = divisors[i + DCTSIZE2 * 3];

    if (temp < 0) {
      temp = -temp;
      product = (UDCTELEM2)(temp + corr) * recip;
      product >>= shift + sizeof(DCTELEM) * 8;
      temp = (DCTELEM)product;
      temp = -temp;
    } else {
      product = (UDCTELEM2)(temp + corr) * recip;
      product >>= shift + sizeof(DCTELEM) * 8;
      temp = (DCTELEM)product;
    }
    output_ptr[i] = (JCOEF)temp;
  }
#else
  DCTELEM qval;

  for (i = 0; i < DCTSIZE2; i++) {
    qval = divisors[i];
    temp = workspace[i];
    if (temp < 0) {
      temp = -temp;
      temp += qval >> 1;
      if (temp >= qval)
        temp /= qval;
      else
        temp = 0;
      temp = -temp;
    } else {
      temp += qval >> 1;
      if (temp >= qval)
        temp /= qval;
      else
        temp = 0;
    }
    output_ptr[i] = (JCOEF)temp;
  }
#endif
}

GLOBAL(void)
jsimd_quantize_float(JCOEFPTR coef_block, FAST_FLOAT *divisors,
                     FAST_FLOAT *workspace)
{
  FAST_FLOAT temp;
  int i;
  JCOEFPTR output_ptr = coef_block;

  for (i = 0; i < DCTSIZE2; i++) {
    temp = workspace[i] * divisors[i];
    output_ptr[i] = (JCOEF)((int)(temp + (FAST_FLOAT)16384.5) - 16384);
  }
}

GLOBAL(int)
jsimd_can_idct_2x2(void)
{
  if (DCTSIZE != 8)
    return 0;
  if (sizeof(JCOEF) != 2)
    return 0;
  if (BITS_IN_JSAMPLE != 8)
    return 0;
  if (sizeof(JDIMENSION) != 4)
    return 0;

  return loongarch_has_lsx();
}

GLOBAL(int)
jsimd_can_idct_4x4(void)
{
  if (DCTSIZE != 8)
    return 0;
  if (sizeof(JCOEF) != 2)
    return 0;
  if (BITS_IN_JSAMPLE != 8)
    return 0;
  if (sizeof(JDIMENSION) != 4)
    return 0;

  return loongarch_has_lsx();
}

GLOBAL(int)
jsimd_can_idct_6x6(void)
{
  if (DCTSIZE != 8)
    return 0;
  if (sizeof(JCOEF) != 2)
    return 0;
  if (BITS_IN_JSAMPLE != 8)
    return 0;
  if (sizeof(JDIMENSION) != 4)
    return 0;

  return loongarch_has_lsx();
}

GLOBAL(int)
jsimd_can_idct_12x12(void)
{
  if (DCTSIZE != 8)
    return 0;
  if (sizeof(JCOEF) != 2)
    return 0;
  if (BITS_IN_JSAMPLE != 8)
    return 0;
  if (sizeof(JDIMENSION) != 4)
    return 0;

  return loongarch_has_lsx();
}

GLOBAL(void)
jsimd_idct_2x2(j_decompress_ptr cinfo, jpeg_component_info *compptr,
               JCOEFPTR coef_block, JSAMPARRAY output_buf,
               JDIMENSION output_col)
{
  jpeg_idct_2x2(cinfo, compptr, coef_block, output_buf, output_col);
}

GLOBAL(void)
jsimd_idct_4x4(j_decompress_ptr cinfo, jpeg_component_info *compptr,
               JCOEFPTR coef_block, JSAMPARRAY output_buf,
               JDIMENSION output_col)
{
  jpeg_idct_4x4(cinfo, compptr, coef_block, output_buf, output_col);
}

GLOBAL(void)
jsimd_idct_6x6(j_decompress_ptr cinfo, jpeg_component_info *compptr,
               JCOEFPTR coef_block, JSAMPARRAY output_buf,
               JDIMENSION output_col)
{
  jpeg_idct_6x6(cinfo, compptr, coef_block, output_buf, output_col);
}

GLOBAL(void)
jsimd_idct_12x12(j_decompress_ptr cinfo, jpeg_component_info *compptr,
                 JCOEFPTR coef_block, JSAMPARRAY output_buf,
                 JDIMENSION output_col)
{
  jpeg_idct_12x12(cinfo, compptr, coef_block, output_buf, output_col);
}

GLOBAL(int)
jsimd_can_idct_islow(void)
{
  if (DCTSIZE != 8)
    return 0;
  if (sizeof(JCOEF) != 2)
    return 0;
  if (BITS_IN_JSAMPLE != 8)
    return 0;
  if (sizeof(JDIMENSION) != 4)
    return 0;

  return loongarch_has_lsx();
}

GLOBAL(int)
jsimd_can_idct_ifast(void)
{
  if (DCTSIZE != 8)
    return 0;
  if (sizeof(JCOEF) != 2)
    return 0;
  if (BITS_IN_JSAMPLE != 8)
    return 0;
  if (sizeof(JDIMENSION) != 4)
    return 0;

  return loongarch_has_lsx();
}

GLOBAL(int)
jsimd_can_idct_float(void)
{
  if (DCTSIZE != 8)
    return 0;
  if (sizeof(JCOEF) != 2)
    return 0;
  if (BITS_IN_JSAMPLE != 8)
    return 0;
  if (sizeof(JDIMENSION) != 4)
    return 0;

  return loongarch_has_lsx();
}

GLOBAL(void)
jsimd_idct_islow(j_decompress_ptr cinfo, jpeg_component_info *compptr,
                 JCOEFPTR coef_block, JSAMPARRAY output_buf,
                 JDIMENSION output_col)
{
  jpeg_idct_islow(cinfo, compptr, coef_block, output_buf, output_col);
}

GLOBAL(void)
jsimd_idct_ifast(j_decompress_ptr cinfo, jpeg_component_info *compptr,
                 JCOEFPTR coef_block, JSAMPARRAY output_buf,
                 JDIMENSION output_col)
{
  jpeg_idct_ifast(cinfo, compptr, coef_block, output_buf, output_col);
}

GLOBAL(void)
jsimd_idct_float(j_decompress_ptr cinfo, jpeg_component_info *compptr,
                 JCOEFPTR coef_block, JSAMPARRAY output_buf,
                 JDIMENSION output_col)
{
  jpeg_idct_float(cinfo, compptr, coef_block, output_buf, output_col);
}

typedef size_t loongarch_bit_buf_type;
typedef unsigned long long loongarch_simd_bit_buf_type;

typedef struct {
  union {
    loongarch_bit_buf_type c;
    loongarch_simd_bit_buf_type simd;
  } put_buffer;
  int free_bits;
  int last_dc_val[MAX_COMPS_IN_SCAN];
} loongarch_savable_state;

typedef struct {
  JOCTET *next_output_byte;
  size_t free_in_buffer;
  loongarch_savable_state cur;
  j_compress_ptr cinfo;
  int simd;
} loongarch_working_state;

#define LOONGARCH_SIMD_BIT_BUF_SIZE \
  ((int)(sizeof(loongarch_simd_bit_buf_type) * CHAR_BIT))

LOCAL(int)
loongarch_jpeg_nbits(unsigned int x)
{
  if (x == 0)
    return 0;
#if defined(__GNUC__) || defined(__clang__)
  return (int)(sizeof(unsigned int) * CHAR_BIT) - __builtin_clz(x);
#else
  {
    int nbits = 0;
    while (x) {
      nbits++;
      x >>= 1;
    }
    return nbits;
  }
#endif
}

GLOBAL(int)
jsimd_can_huff_encode_one_block(void)
{
  if (DCTSIZE != 8)
    return 0;
  if (sizeof(JCOEF) != 2)
    return 0;
  if (SIZEOF_SIZE_T != 8)
    return 0;

  return loongarch_has_lsx();
}

#define LOONGARCH_EMIT_BYTE(b) { \
  buffer[0] = (JOCTET)(b); \
  buffer[1] = 0; \
  buffer -= -2 + ((JOCTET)(b) < 0xFF); \
}

#define LOONGARCH_FLUSH() { \
  if (put_buffer & 0x8080808080808080ULL & \
      ~(put_buffer + 0x0101010101010101ULL)) { \
    LOONGARCH_EMIT_BYTE(put_buffer >> 56) \
    LOONGARCH_EMIT_BYTE(put_buffer >> 48) \
    LOONGARCH_EMIT_BYTE(put_buffer >> 40) \
    LOONGARCH_EMIT_BYTE(put_buffer >> 32) \
    LOONGARCH_EMIT_BYTE(put_buffer >> 24) \
    LOONGARCH_EMIT_BYTE(put_buffer >> 16) \
    LOONGARCH_EMIT_BYTE(put_buffer >>  8) \
    LOONGARCH_EMIT_BYTE(put_buffer      ) \
  } else { \
    buffer[0] = (JOCTET)(put_buffer >> 56); \
    buffer[1] = (JOCTET)(put_buffer >> 48); \
    buffer[2] = (JOCTET)(put_buffer >> 40); \
    buffer[3] = (JOCTET)(put_buffer >> 32); \
    buffer[4] = (JOCTET)(put_buffer >> 24); \
    buffer[5] = (JOCTET)(put_buffer >> 16); \
    buffer[6] = (JOCTET)(put_buffer >> 8); \
    buffer[7] = (JOCTET)(put_buffer); \
    buffer += 8; \
  } \
}

#define LOONGARCH_PUT_AND_FLUSH(code, size) { \
  put_buffer = (put_buffer << ((size) + free_bits)) | \
               ((loongarch_simd_bit_buf_type)(code) >> -free_bits); \
  LOONGARCH_FLUSH() \
  free_bits += LOONGARCH_SIMD_BIT_BUF_SIZE; \
  put_buffer = (loongarch_simd_bit_buf_type)(code); \
}

#define LOONGARCH_PUT_BITS(code, size) { \
  free_bits -= (size); \
  if (free_bits < 0) \
    LOONGARCH_PUT_AND_FLUSH(code, size) \
  else \
    put_buffer = (put_buffer << (size)) | (loongarch_simd_bit_buf_type)(code); \
}

#define LOONGARCH_PUT_CODE(code, size) { \
  temp &= (((JLONG)1) << nbits) - 1; \
  temp |= (code) << nbits; \
  nbits += (size); \
  LOONGARCH_PUT_BITS(temp, nbits) \
}

GLOBAL(JOCTET *)
jsimd_huff_encode_one_block(void *state, JOCTET *buffer, JCOEFPTR block,
                            int last_dc_val, c_derived_tbl *dctbl,
                            c_derived_tbl *actbl)
{
  loongarch_working_state *state_ptr = (loongarch_working_state *)state;
  int max_coef_bits = state_ptr->cinfo->data_precision + 2;
  int temp, nbits, free_bits;
  loongarch_simd_bit_buf_type put_buffer;

  free_bits = state_ptr->cur.free_bits;
  put_buffer = state_ptr->cur.put_buffer.simd;

  temp = block[0] - last_dc_val;
  nbits = temp >> (CHAR_BIT * sizeof(int) - 1);
  temp += nbits;
  nbits ^= temp;
  nbits = loongarch_jpeg_nbits((unsigned int)nbits);
  if (nbits > max_coef_bits + 1)
    ERREXIT(state_ptr->cinfo, JERR_BAD_DCT_COEF);

  LOONGARCH_PUT_CODE(dctbl->ehufco[nbits], dctbl->ehufsi[nbits])

  {
    int r = 0;

#define LOONGARCH_KLOOP(jpeg_natural_order_of_k) { \
  if ((temp = block[jpeg_natural_order_of_k]) == 0) { \
    r += 16; \
  } else { \
    nbits = temp >> (CHAR_BIT * sizeof(int) - 1); \
    temp += nbits; \
    nbits ^= temp; \
    nbits = loongarch_jpeg_nbits((unsigned int)nbits); \
    if (nbits > max_coef_bits) \
      ERREXIT(state_ptr->cinfo, JERR_BAD_DCT_COEF); \
    while (r >= 16 * 16) { \
      r -= 16 * 16; \
      LOONGARCH_PUT_BITS(actbl->ehufco[0xf0], actbl->ehufsi[0xf0]) \
    } \
    r += nbits; \
    LOONGARCH_PUT_CODE(actbl->ehufco[r], actbl->ehufsi[r]) \
    r = 0; \
  } \
}

    LOONGARCH_KLOOP(1);   LOONGARCH_KLOOP(8);
    LOONGARCH_KLOOP(16);  LOONGARCH_KLOOP(9);
    LOONGARCH_KLOOP(2);   LOONGARCH_KLOOP(3);
    LOONGARCH_KLOOP(10);  LOONGARCH_KLOOP(17);
    LOONGARCH_KLOOP(24);  LOONGARCH_KLOOP(32);
    LOONGARCH_KLOOP(25);  LOONGARCH_KLOOP(18);
    LOONGARCH_KLOOP(11);  LOONGARCH_KLOOP(4);
    LOONGARCH_KLOOP(5);   LOONGARCH_KLOOP(12);
    LOONGARCH_KLOOP(19);  LOONGARCH_KLOOP(26);
    LOONGARCH_KLOOP(33);  LOONGARCH_KLOOP(40);
    LOONGARCH_KLOOP(48);  LOONGARCH_KLOOP(41);
    LOONGARCH_KLOOP(34);  LOONGARCH_KLOOP(27);
    LOONGARCH_KLOOP(20);  LOONGARCH_KLOOP(13);
    LOONGARCH_KLOOP(6);   LOONGARCH_KLOOP(7);
    LOONGARCH_KLOOP(14);  LOONGARCH_KLOOP(21);
    LOONGARCH_KLOOP(28);  LOONGARCH_KLOOP(35);
    LOONGARCH_KLOOP(42);  LOONGARCH_KLOOP(49);
    LOONGARCH_KLOOP(56);  LOONGARCH_KLOOP(57);
    LOONGARCH_KLOOP(50);  LOONGARCH_KLOOP(43);
    LOONGARCH_KLOOP(36);  LOONGARCH_KLOOP(29);
    LOONGARCH_KLOOP(22);  LOONGARCH_KLOOP(15);
    LOONGARCH_KLOOP(23);  LOONGARCH_KLOOP(30);
    LOONGARCH_KLOOP(37);  LOONGARCH_KLOOP(44);
    LOONGARCH_KLOOP(51);  LOONGARCH_KLOOP(58);
    LOONGARCH_KLOOP(59);  LOONGARCH_KLOOP(52);
    LOONGARCH_KLOOP(45);  LOONGARCH_KLOOP(38);
    LOONGARCH_KLOOP(31);  LOONGARCH_KLOOP(39);
    LOONGARCH_KLOOP(46);  LOONGARCH_KLOOP(53);
    LOONGARCH_KLOOP(60);  LOONGARCH_KLOOP(61);
    LOONGARCH_KLOOP(54);  LOONGARCH_KLOOP(47);
    LOONGARCH_KLOOP(55);  LOONGARCH_KLOOP(62);
    LOONGARCH_KLOOP(63);

    if (r > 0) {
      LOONGARCH_PUT_BITS(actbl->ehufco[0], actbl->ehufsi[0])
    }
#undef LOONGARCH_KLOOP
  }

  state_ptr->cur.put_buffer.simd = put_buffer;
  state_ptr->cur.free_bits = free_bits;

  return buffer;
}

#undef LOONGARCH_PUT_CODE
#undef LOONGARCH_PUT_BITS
#undef LOONGARCH_PUT_AND_FLUSH
#undef LOONGARCH_FLUSH
#undef LOONGARCH_EMIT_BYTE

GLOBAL(int)
jsimd_can_encode_mcu_AC_first_prepare(void)
{
  if (DCTSIZE != 8)
    return 0;
  if (sizeof(JCOEF) != 2)
    return 0;
  if (SIZEOF_SIZE_T != 8)
    return 0;

  return loongarch_has_lsx();
}

#define LOONGARCH_COMPUTE_ABSVALUES_AC_FIRST(Sl) { \
  for (k = 0; k < (Sl); k++) { \
    temp = block[jpeg_natural_order_start[k]]; \
    if (temp == 0) \
      continue; \
    temp2 = temp >> (CHAR_BIT * sizeof(int) - 1); \
    temp ^= temp2; \
    temp -= temp2; \
    temp >>= Al; \
    if (temp == 0) \
      continue; \
    temp2 ^= temp; \
    values[k] = (UJCOEF)temp; \
    values[k + DCTSIZE2] = (UJCOEF)temp2; \
    zerobits |= ((size_t)1U) << k; \
  } \
}

GLOBAL(void)
jsimd_encode_mcu_AC_first_prepare(const JCOEF *block,
                                  const int *jpeg_natural_order_start, int Sl,
                                  int Al, UJCOEF *values, size_t *bits)
{
  int k, temp, temp2;
  size_t zerobits = 0U;
  int Sl0 = Sl;

#if SIZEOF_SIZE_T == 4
  if (Sl0 > 32)
    Sl0 = 32;
#endif

  LOONGARCH_COMPUTE_ABSVALUES_AC_FIRST(Sl0);

  bits[0] = zerobits;
#if SIZEOF_SIZE_T == 4
  zerobits = 0U;

  if (Sl > 32) {
    Sl -= 32;
    jpeg_natural_order_start += 32;
    values += 32;

    LOONGARCH_COMPUTE_ABSVALUES_AC_FIRST(Sl);
  }
  bits[1] = zerobits;
#endif
}

#undef LOONGARCH_COMPUTE_ABSVALUES_AC_FIRST

GLOBAL(int)
jsimd_can_encode_mcu_AC_refine_prepare(void)
{
  if (DCTSIZE != 8)
    return 0;
  if (sizeof(JCOEF) != 2)
    return 0;
  if (SIZEOF_SIZE_T != 8)
    return 0;

  return loongarch_has_lsx();
}

#define LOONGARCH_COMPUTE_ABSVALUES_AC_REFINE(Sl, koffset) { \
  for (k = 0; k < (Sl); k++) { \
    temp = block[jpeg_natural_order_start[k]]; \
    temp2 = temp >> (CHAR_BIT * sizeof(int) - 1); \
    temp ^= temp2; \
    temp -= temp2; \
    temp >>= Al; \
    if (temp != 0) { \
      zerobits |= ((size_t)1U) << k; \
      signbits |= ((size_t)(temp2 + 1)) << k; \
    } \
    absvalues[k] = (UJCOEF)temp; \
    if (temp == 1) \
      EOB = k + (koffset); \
  } \
}

GLOBAL(int)
jsimd_encode_mcu_AC_refine_prepare(const JCOEF *block,
                                   const int *jpeg_natural_order_start, int Sl,
                                   int Al, UJCOEF *absvalues, size_t *bits)
{
  int k, temp, temp2;
  int EOB = 0;
  size_t zerobits = 0U, signbits = 0U;
  int Sl0 = Sl;

#if SIZEOF_SIZE_T == 4
  if (Sl0 > 32)
    Sl0 = 32;
#endif

  LOONGARCH_COMPUTE_ABSVALUES_AC_REFINE(Sl0, 0);

  bits[0] = zerobits;
#if SIZEOF_SIZE_T == 8
  bits[1] = signbits;
#else
  bits[2] = signbits;

  zerobits = 0U;
  signbits = 0U;

  if (Sl > 32) {
    Sl -= 32;
    jpeg_natural_order_start += 32;
    absvalues += 32;

    LOONGARCH_COMPUTE_ABSVALUES_AC_REFINE(Sl, 32);
  }

  bits[1] = zerobits;
  bits[3] = signbits;
#endif

  return EOB;
}

#undef LOONGARCH_COMPUTE_ABSVALUES_AC_REFINE
