/*
 * jsimd_loongarch.h
 *
 * Copyright (C) 2026, LoongArch Flutter/Dart port contributors.
 *
 * Based on the Arm Neon SIMD extension for the IJG JPEG library.
 * For conditions of distribution and use, see copyright notice in jsimdext.inc.
 */

/* RGB & extended RGB --> YCbCr Colorspace Conversion */
EXTERN(void) jsimd_rgb_ycc_convert_lsx
  (JDIMENSION img_width, JSAMPARRAY input_buf, JSAMPIMAGE output_buf,
   JDIMENSION output_row, int num_rows);
EXTERN(void) jsimd_extrgb_ycc_convert_lsx
  (JDIMENSION img_width, JSAMPARRAY input_buf, JSAMPIMAGE output_buf,
   JDIMENSION output_row, int num_rows);
EXTERN(void) jsimd_extrgbx_ycc_convert_lsx
  (JDIMENSION img_width, JSAMPARRAY input_buf, JSAMPIMAGE output_buf,
   JDIMENSION output_row, int num_rows);
EXTERN(void) jsimd_extbgr_ycc_convert_lsx
  (JDIMENSION img_width, JSAMPARRAY input_buf, JSAMPIMAGE output_buf,
   JDIMENSION output_row, int num_rows);
EXTERN(void) jsimd_extbgrx_ycc_convert_lsx
  (JDIMENSION img_width, JSAMPARRAY input_buf, JSAMPIMAGE output_buf,
   JDIMENSION output_row, int num_rows);
EXTERN(void) jsimd_extxbgr_ycc_convert_lsx
  (JDIMENSION img_width, JSAMPARRAY input_buf, JSAMPIMAGE output_buf,
   JDIMENSION output_row, int num_rows);
EXTERN(void) jsimd_extxrgb_ycc_convert_lsx
  (JDIMENSION img_width, JSAMPARRAY input_buf, JSAMPIMAGE output_buf,
   JDIMENSION output_row, int num_rows);

EXTERN(void) jsimd_rgb_ycc_convert_lasx
  (JDIMENSION img_width, JSAMPARRAY input_buf, JSAMPIMAGE output_buf,
   JDIMENSION output_row, int num_rows);
EXTERN(void) jsimd_extrgb_ycc_convert_lasx
  (JDIMENSION img_width, JSAMPARRAY input_buf, JSAMPIMAGE output_buf,
   JDIMENSION output_row, int num_rows);
EXTERN(void) jsimd_extrgbx_ycc_convert_lasx
  (JDIMENSION img_width, JSAMPARRAY input_buf, JSAMPIMAGE output_buf,
   JDIMENSION output_row, int num_rows);
EXTERN(void) jsimd_extbgr_ycc_convert_lasx
  (JDIMENSION img_width, JSAMPARRAY input_buf, JSAMPIMAGE output_buf,
   JDIMENSION output_row, int num_rows);
EXTERN(void) jsimd_extbgrx_ycc_convert_lasx
  (JDIMENSION img_width, JSAMPARRAY input_buf, JSAMPIMAGE output_buf,
   JDIMENSION output_row, int num_rows);
EXTERN(void) jsimd_extxbgr_ycc_convert_lasx
  (JDIMENSION img_width, JSAMPARRAY input_buf, JSAMPIMAGE output_buf,
   JDIMENSION output_row, int num_rows);
EXTERN(void) jsimd_extxrgb_ycc_convert_lasx
  (JDIMENSION img_width, JSAMPARRAY input_buf, JSAMPIMAGE output_buf,
   JDIMENSION output_row, int num_rows);

/* RGB & extended RGB --> Grayscale Colorspace Conversion */
EXTERN(void) jsimd_rgb_gray_convert_lsx
  (JDIMENSION img_width, JSAMPARRAY input_buf, JSAMPIMAGE output_buf,
   JDIMENSION output_row, int num_rows);
EXTERN(void) jsimd_extrgb_gray_convert_lsx
  (JDIMENSION img_width, JSAMPARRAY input_buf, JSAMPIMAGE output_buf,
   JDIMENSION output_row, int num_rows);
EXTERN(void) jsimd_extrgbx_gray_convert_lsx
  (JDIMENSION img_width, JSAMPARRAY input_buf, JSAMPIMAGE output_buf,
   JDIMENSION output_row, int num_rows);
EXTERN(void) jsimd_extbgr_gray_convert_lsx
  (JDIMENSION img_width, JSAMPARRAY input_buf, JSAMPIMAGE output_buf,
   JDIMENSION output_row, int num_rows);
EXTERN(void) jsimd_extbgrx_gray_convert_lsx
  (JDIMENSION img_width, JSAMPARRAY input_buf, JSAMPIMAGE output_buf,
   JDIMENSION output_row, int num_rows);
EXTERN(void) jsimd_extxbgr_gray_convert_lsx
  (JDIMENSION img_width, JSAMPARRAY input_buf, JSAMPIMAGE output_buf,
   JDIMENSION output_row, int num_rows);
EXTERN(void) jsimd_extxrgb_gray_convert_lsx
  (JDIMENSION img_width, JSAMPARRAY input_buf, JSAMPIMAGE output_buf,
   JDIMENSION output_row, int num_rows);

EXTERN(void) jsimd_rgb_gray_convert_lasx
  (JDIMENSION img_width, JSAMPARRAY input_buf, JSAMPIMAGE output_buf,
   JDIMENSION output_row, int num_rows);
EXTERN(void) jsimd_extrgb_gray_convert_lasx
  (JDIMENSION img_width, JSAMPARRAY input_buf, JSAMPIMAGE output_buf,
   JDIMENSION output_row, int num_rows);
EXTERN(void) jsimd_extrgbx_gray_convert_lasx
  (JDIMENSION img_width, JSAMPARRAY input_buf, JSAMPIMAGE output_buf,
   JDIMENSION output_row, int num_rows);
EXTERN(void) jsimd_extbgr_gray_convert_lasx
  (JDIMENSION img_width, JSAMPARRAY input_buf, JSAMPIMAGE output_buf,
   JDIMENSION output_row, int num_rows);
EXTERN(void) jsimd_extbgrx_gray_convert_lasx
  (JDIMENSION img_width, JSAMPARRAY input_buf, JSAMPIMAGE output_buf,
   JDIMENSION output_row, int num_rows);
EXTERN(void) jsimd_extxbgr_gray_convert_lasx
  (JDIMENSION img_width, JSAMPARRAY input_buf, JSAMPIMAGE output_buf,
   JDIMENSION output_row, int num_rows);
EXTERN(void) jsimd_extxrgb_gray_convert_lasx
  (JDIMENSION img_width, JSAMPARRAY input_buf, JSAMPIMAGE output_buf,
   JDIMENSION output_row, int num_rows);
