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
 * predicates return 1 are accelerated; the remaining entry points are stubs.
 */

#define jsimd_can_rgb_ycc jsimd_can_rgb_ycc_none
#define jsimd_can_rgb_gray jsimd_can_rgb_gray_none
#define jsimd_rgb_ycc_convert jsimd_rgb_ycc_convert_none
#define jsimd_rgb_gray_convert jsimd_rgb_gray_convert_none
#include "../../jsimd_none.c"
#undef jsimd_can_rgb_ycc
#undef jsimd_can_rgb_gray
#undef jsimd_rgb_ycc_convert
#undef jsimd_rgb_gray_convert

#include "../jsimd.h"
#include "jsimd_loongarch.h"

#include <ctype.h>

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
