/*
 * jccolext-loongarch.c
 *
 * Copyright (C) 2026, LoongArch Flutter/Dart port contributors.
 *
 * Based on the Arm Neon colorspace conversion code.
 * For conditions of distribution and use, see copyright notice in jsimdext.inc.
 */

/* This file is included by jccolor-lsx.c and jccolor-lasx.c. */

void JSIMD_RGB_YCC_CONVERT(JDIMENSION image_width, JSAMPARRAY input_buf,
                           JSAMPIMAGE output_buf, JDIMENSION output_row,
                           int num_rows)
{
  JSAMPROW inptr;
  JSAMPROW outptr0, outptr1, outptr2;

  while (--num_rows >= 0) {
    JDIMENSION col;

    inptr = *input_buf++;
    outptr0 = output_buf[0][output_row];
    outptr1 = output_buf[1][output_row];
    outptr2 = output_buf[2][output_row];
    output_row++;

    for (col = 0; col + LOONGARCH_SIMD_LANES <= image_width;
         col += LOONGARCH_SIMD_LANES) {
      uint32_t r[LOONGARCH_SIMD_LANES];
      uint32_t g[LOONGARCH_SIMD_LANES];
      uint32_t b[LOONGARCH_SIMD_LANES];
      int i;

      for (i = 0; i < LOONGARCH_SIMD_LANES; i++) {
        r[i] = inptr[i * RGB_PIXELSIZE + RGB_RED];
        g[i] = inptr[i * RGB_PIXELSIZE + RGB_GREEN];
        b[i] = inptr[i * RGB_PIXELSIZE + RGB_BLUE];
      }

      LOONGARCH_YCC_BLOCK(r, g, b, outptr0 + col, outptr1 + col,
                          outptr2 + col);
      inptr += LOONGARCH_SIMD_LANES * RGB_PIXELSIZE;
    }

    for (; col < image_width; col++) {
      int r = inptr[RGB_RED];
      int g = inptr[RGB_GREEN];
      int b = inptr[RGB_BLUE];

      outptr0[col] = loongarch_y_from_rgb(r, g, b);
      outptr1[col] = loongarch_cb_from_rgb(r, g, b);
      outptr2[col] = loongarch_cr_from_rgb(r, g, b);
      inptr += RGB_PIXELSIZE;
    }
  }
}

void JSIMD_RGB_GRAY_CONVERT(JDIMENSION image_width, JSAMPARRAY input_buf,
                            JSAMPIMAGE output_buf, JDIMENSION output_row,
                            int num_rows)
{
  JSAMPROW inptr;
  JSAMPROW outptr;

  while (--num_rows >= 0) {
    JDIMENSION col;

    inptr = *input_buf++;
    outptr = output_buf[0][output_row];
    output_row++;

    for (col = 0; col + LOONGARCH_SIMD_LANES <= image_width;
         col += LOONGARCH_SIMD_LANES) {
      uint32_t r[LOONGARCH_SIMD_LANES];
      uint32_t g[LOONGARCH_SIMD_LANES];
      uint32_t b[LOONGARCH_SIMD_LANES];
      int i;

      for (i = 0; i < LOONGARCH_SIMD_LANES; i++) {
        r[i] = inptr[i * RGB_PIXELSIZE + RGB_RED];
        g[i] = inptr[i * RGB_PIXELSIZE + RGB_GREEN];
        b[i] = inptr[i * RGB_PIXELSIZE + RGB_BLUE];
      }

      LOONGARCH_GRAY_BLOCK(r, g, b, outptr + col);
      inptr += LOONGARCH_SIMD_LANES * RGB_PIXELSIZE;
    }

    for (; col < image_width; col++) {
      outptr[col] = loongarch_y_from_rgb(inptr[RGB_RED], inptr[RGB_GREEN],
                                         inptr[RGB_BLUE]);
      inptr += RGB_PIXELSIZE;
    }
  }
}
