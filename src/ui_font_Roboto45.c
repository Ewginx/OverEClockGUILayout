/*******************************************************************************
 * Size: 45 px
 * Bpp: 2
 * Opts: 
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef UI_FONT_ROBOTO45
#define UI_FONT_ROBOTO45 1
#endif

#if UI_FONT_ROBOTO45

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0030 "0" */
    0x0, 0x6, 0xff, 0xe4, 0x0, 0x0, 0x3, 0xff,
    0xff, 0xf8, 0x0, 0x1, 0xff, 0xff, 0xff, 0xf0,
    0x0, 0x3f, 0xff, 0xff, 0xff, 0x80, 0xf, 0xff,
    0xd5, 0xbf, 0xfd, 0x1, 0xff, 0xe0, 0x0, 0xff,
    0xf0, 0x2f, 0xfc, 0x0, 0x3, 0xff, 0x3, 0xff,
    0x40, 0x0, 0x3f, 0xf8, 0x3f, 0xf0, 0x0, 0x2,
    0xff, 0xc7, 0xff, 0x0, 0x0, 0x1f, 0xfc, 0xbf,
    0xe0, 0x0, 0x0, 0xff, 0xcb, 0xfe, 0x0, 0x0,
    0xf, 0xfc, 0xbf, 0xe0, 0x0, 0x0, 0xff, 0xcb,
    0xfe, 0x0, 0x0, 0xf, 0xfc, 0xbf, 0xe0, 0x0,
    0x0, 0xff, 0xdb, 0xfe, 0x0, 0x0, 0xf, 0xfd,
    0xbf, 0xe0, 0x0, 0x0, 0xff, 0xdb, 0xfe, 0x0,
    0x0, 0xf, 0xfd, 0xbf, 0xe0, 0x0, 0x0, 0xff,
    0xcb, 0xfe, 0x0, 0x0, 0xf, 0xfc, 0xbf, 0xe0,
    0x0, 0x0, 0xff, 0xcb, 0xfe, 0x0, 0x0, 0xf,
    0xfc, 0x7f, 0xf0, 0x0, 0x1, 0xff, 0xc3, 0xff,
    0x0, 0x0, 0x2f, 0xfc, 0x3f, 0xf4, 0x0, 0x3,
    0xff, 0x82, 0xff, 0xc0, 0x0, 0x3f, 0xf0, 0x1f,
    0xfe, 0x0, 0xf, 0xff, 0x0, 0xbf, 0xfd, 0x5b,
    0xff, 0xd0, 0x3, 0xff, 0xff, 0xff, 0xf8, 0x0,
    0xf, 0xff, 0xff, 0xfe, 0x0, 0x0, 0x2f, 0xff,
    0xff, 0x80, 0x0, 0x0, 0x2f, 0xfe, 0x40, 0x0,

    /* U+0031 "1" */
    0x0, 0x0, 0x1, 0xf0, 0x0, 0x6, 0xff, 0x0,
    0xb, 0xff, 0xf0, 0x1f, 0xff, 0xff, 0x2f, 0xff,
    0xff, 0xf7, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xbf,
    0xf7, 0xfd, 0x7, 0xff, 0x74, 0x0, 0x7f, 0xf0,
    0x0, 0x7, 0xff, 0x0, 0x0, 0x7f, 0xf0, 0x0,
    0x7, 0xff, 0x0, 0x0, 0x7f, 0xf0, 0x0, 0x7,
    0xff, 0x0, 0x0, 0x7f, 0xf0, 0x0, 0x7, 0xff,
    0x0, 0x0, 0x7f, 0xf0, 0x0, 0x7, 0xff, 0x0,
    0x0, 0x7f, 0xf0, 0x0, 0x7, 0xff, 0x0, 0x0,
    0x7f, 0xf0, 0x0, 0x7, 0xff, 0x0, 0x0, 0x7f,
    0xf0, 0x0, 0x7, 0xff, 0x0, 0x0, 0x7f, 0xf0,
    0x0, 0x7, 0xff, 0x0, 0x0, 0x7f, 0xf0, 0x0,
    0x7, 0xff, 0x0, 0x0, 0x7f, 0xf0, 0x0, 0x7,
    0xff, 0x0, 0x0, 0x7f, 0xf0, 0x0, 0x7, 0xff,

    /* U+0032 "2" */
    0x0, 0x1, 0xbf, 0xf9, 0x0, 0x0, 0x0, 0x7f,
    0xff, 0xff, 0x80, 0x0, 0xf, 0xff, 0xff, 0xff,
    0xc0, 0x0, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xb,
    0xff, 0xe5, 0x6f, 0xff, 0x80, 0x3f, 0xfc, 0x0,
    0xf, 0xff, 0x2, 0xff, 0xc0, 0x0, 0x1f, 0xfd,
    0xf, 0xfe, 0x0, 0x0, 0x3f, 0xf8, 0x3f, 0xf4,
    0x0, 0x0, 0xff, 0xe0, 0xff, 0xc0, 0x0, 0x2,
    0xff, 0x80, 0x0, 0x0, 0x0, 0xf, 0xfd, 0x0,
    0x0, 0x0, 0x0, 0x3f, 0xf0, 0x0, 0x0, 0x0,
    0x2, 0xff, 0xc0, 0x0, 0x0, 0x0, 0xf, 0xfd,
    0x0, 0x0, 0x0, 0x0, 0xff, 0xf0, 0x0, 0x0,
    0x0, 0xb, 0xff, 0x0, 0x0, 0x0, 0x0, 0xbf,
    0xf4, 0x0, 0x0, 0x0, 0x7, 0xff, 0x80, 0x0,
    0x0, 0x0, 0x7f, 0xfc, 0x0, 0x0, 0x0, 0x7,
    0xff, 0xc0, 0x0, 0x0, 0x0, 0x7f, 0xfc, 0x0,
    0x0, 0x0, 0x3, 0xff, 0xc0, 0x0, 0x0, 0x0,
    0x3f, 0xfc, 0x0, 0x0, 0x0, 0x3, 0xff, 0xc0,
    0x0, 0x0, 0x0, 0x3f, 0xfc, 0x0, 0x0, 0x0,
    0x3, 0xff, 0xc0, 0x0, 0x0, 0x0, 0x3f, 0xfd,
    0x0, 0x0, 0x0, 0x3, 0xff, 0xe0, 0x0, 0x0,
    0x0, 0x2f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xbf,
    0xff, 0xff, 0xff, 0xff, 0xf2, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xcb, 0xff, 0xff, 0xff, 0xff, 0xff,

    /* U+0033 "3" */
    0x0, 0x1, 0xbf, 0xf9, 0x0, 0x0, 0x2, 0xff,
    0xff, 0xfe, 0x0, 0x1, 0xff, 0xff, 0xff, 0xfc,
    0x0, 0x3f, 0xff, 0xff, 0xff, 0xf0, 0xf, 0xff,
    0xe5, 0x6f, 0xff, 0x81, 0xff, 0xe0, 0x0, 0x3f,
    0xfc, 0x2f, 0xfc, 0x0, 0x1, 0xff, 0xd3, 0xff,
    0x40, 0x0, 0xf, 0xfd, 0x15, 0x50, 0x0, 0x0,
    0xff, 0xd0, 0x0, 0x0, 0x0, 0xf, 0xfd, 0x0,
    0x0, 0x0, 0x0, 0xff, 0xc0, 0x0, 0x0, 0x0,
    0x3f, 0xf8, 0x0, 0x0, 0x0, 0x1f, 0xff, 0x0,
    0x0, 0x1f, 0xff, 0xff, 0xc0, 0x0, 0x1, 0xff,
    0xff, 0xd0, 0x0, 0x0, 0x1f, 0xff, 0xfe, 0x0,
    0x0, 0x1, 0xff, 0xff, 0xfd, 0x0, 0x0, 0x0,
    0x6, 0xff, 0xf4, 0x0, 0x0, 0x0, 0x3, 0xff,
    0xc0, 0x0, 0x0, 0x0, 0xf, 0xfd, 0x0, 0x0,
    0x0, 0x0, 0xbf, 0xe0, 0x0, 0x0, 0x0, 0x7,
    0xff, 0x0, 0x0, 0x0, 0x0, 0x7f, 0xf3, 0xff,
    0x0, 0x0, 0x7, 0xff, 0x3f, 0xf4, 0x0, 0x0,
    0xbf, 0xf3, 0xff, 0xc0, 0x0, 0xf, 0xfd, 0x2f,
    0xfe, 0x0, 0x3, 0xff, 0xc0, 0xff, 0xfd, 0x46,
    0xff, 0xf8, 0x7, 0xff, 0xff, 0xff, 0xff, 0x0,
    0x1f, 0xff, 0xff, 0xff, 0xc0, 0x0, 0x2f, 0xff,
    0xff, 0xd0, 0x0, 0x0, 0x1b, 0xff, 0x90, 0x0,

    /* U+0034 "4" */
    0x0, 0x0, 0x0, 0x1f, 0xfd, 0x0, 0x0, 0x0,
    0x0, 0x3f, 0xfd, 0x0, 0x0, 0x0, 0x0, 0xbf,
    0xfd, 0x0, 0x0, 0x0, 0x1, 0xff, 0xfd, 0x0,
    0x0, 0x0, 0x3, 0xff, 0xfd, 0x0, 0x0, 0x0,
    0xb, 0xff, 0xfd, 0x0, 0x0, 0x0, 0xf, 0xff,
    0xfd, 0x0, 0x0, 0x0, 0x3f, 0xff, 0xfd, 0x0,
    0x0, 0x0, 0x7f, 0xdf, 0xfd, 0x0, 0x0, 0x0,
    0xff, 0xcf, 0xfd, 0x0, 0x0, 0x2, 0xff, 0xf,
    0xfd, 0x0, 0x0, 0x7, 0xfe, 0xf, 0xfd, 0x0,
    0x0, 0xf, 0xfc, 0xf, 0xfd, 0x0, 0x0, 0x2f,
    0xf4, 0xf, 0xfd, 0x0, 0x0, 0x7f, 0xe0, 0xf,
    0xfd, 0x0, 0x0, 0xff, 0xc0, 0xf, 0xfd, 0x0,
    0x2, 0xff, 0x40, 0xf, 0xfd, 0x0, 0x3, 0xff,
    0x0, 0xf, 0xfd, 0x0, 0xf, 0xfc, 0x0, 0xf,
    0xfd, 0x0, 0x1f, 0xf8, 0x0, 0xf, 0xfd, 0x0,
    0x3f, 0xf4, 0x0, 0xf, 0xfe, 0x0, 0xbf, 0xff,
    0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd,
    0xbf, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x0, 0x0,
    0x0, 0xf, 0xfd, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xfd, 0x0, 0x0, 0x0, 0x0, 0xf, 0xfd, 0x0,
    0x0, 0x0, 0x0, 0xf, 0xfd, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xfd, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xfd, 0x0, 0x0, 0x0, 0x0, 0xf, 0xfd, 0x0,

    /* U+0035 "5" */
    0x1, 0xff, 0xff, 0xff, 0xff, 0x80, 0x2f, 0xff,
    0xff, 0xff, 0xf8, 0x2, 0xff, 0xff, 0xff, 0xff,
    0x80, 0x3f, 0xff, 0xff, 0xff, 0xf8, 0x3, 0xff,
    0xaa, 0xaa, 0xaa, 0x40, 0x3f, 0xf0, 0x0, 0x0,
    0x0, 0x3, 0xff, 0x0, 0x0, 0x0, 0x0, 0x7f,
    0xe0, 0x0, 0x0, 0x0, 0x7, 0xfe, 0x0, 0x0,
    0x0, 0x0, 0x7f, 0xd0, 0x0, 0x0, 0x0, 0xb,
    0xfd, 0x0, 0x0, 0x0, 0x0, 0xbf, 0xdb, 0xff,
    0xe4, 0x0, 0xf, 0xff, 0xff, 0xff, 0xf0, 0x0,
    0xff, 0xff, 0xff, 0xff, 0xc0, 0xf, 0xff, 0xff,
    0xff, 0xff, 0x0, 0xff, 0xf4, 0x2, 0xff, 0xf4,
    0x1, 0x68, 0x0, 0x7, 0xff, 0xc0, 0x0, 0x0,
    0x0, 0x2f, 0xfd, 0x0, 0x0, 0x0, 0x0, 0xff,
    0xd0, 0x0, 0x0, 0x0, 0xf, 0xfe, 0x0, 0x0,
    0x0, 0x0, 0xbf, 0xe0, 0x0, 0x0, 0x0, 0xb,
    0xff, 0x0, 0x0, 0x0, 0x0, 0xbf, 0xe3, 0xff,
    0x0, 0x0, 0xf, 0xfe, 0x3f, 0xf4, 0x0, 0x0,
    0xff, 0xd2, 0xff, 0xc0, 0x0, 0x2f, 0xfc, 0x1f,
    0xfe, 0x0, 0x7, 0xff, 0x80, 0xbf, 0xfd, 0x46,
    0xff, 0xf0, 0x3, 0xff, 0xff, 0xff, 0xfd, 0x0,
    0xf, 0xff, 0xff, 0xff, 0x80, 0x0, 0x2f, 0xff,
    0xff, 0xd0, 0x0, 0x0, 0x1b, 0xff, 0x90, 0x0,

    /* U+0036 "6" */
    0x0, 0x0, 0x1, 0xbf, 0xc0, 0x0, 0x0, 0x6,
    0xff, 0xfc, 0x0, 0x0, 0x2, 0xff, 0xff, 0xc0,
    0x0, 0x0, 0xff, 0xff, 0xfc, 0x0, 0x0, 0x3f,
    0xff, 0xe9, 0x40, 0x0, 0xf, 0xff, 0xd0, 0x0,
    0x0, 0x2, 0xff, 0xe0, 0x0, 0x0, 0x0, 0x3f,
    0xf4, 0x0, 0x0, 0x0, 0xb, 0xfe, 0x0, 0x0,
    0x0, 0x0, 0xff, 0xc0, 0x0, 0x0, 0x0, 0x1f,
    0xf8, 0x0, 0x0, 0x0, 0x2, 0xff, 0x47, 0xff,
    0xf4, 0x0, 0x3f, 0xf7, 0xff, 0xff, 0xf0, 0x3,
    0xff, 0xff, 0xff, 0xff, 0xc0, 0x3f, 0xff, 0xff,
    0xff, 0xff, 0x7, 0xff, 0xfd, 0x2, 0xff, 0xf4,
    0x7f, 0xfd, 0x0, 0x7, 0xff, 0xc7, 0xff, 0x80,
    0x0, 0x2f, 0xfc, 0x7f, 0xf0, 0x0, 0x0, 0xff,
    0xd7, 0xff, 0x0, 0x0, 0xf, 0xfe, 0x7f, 0xf0,
    0x0, 0x0, 0xbf, 0xe7, 0xff, 0x0, 0x0, 0xb,
    0xfe, 0x3f, 0xf0, 0x0, 0x0, 0xbf, 0xe3, 0xff,
    0x40, 0x0, 0xf, 0xfe, 0x2f, 0xf8, 0x0, 0x0,
    0xff, 0xd1, 0xff, 0xd0, 0x0, 0x2f, 0xfc, 0xf,
    0xff, 0x0, 0x7, 0xff, 0x80, 0x3f, 0xfe, 0x57,
    0xff, 0xf0, 0x1, 0xff, 0xff, 0xff, 0xfd, 0x0,
    0x7, 0xff, 0xff, 0xff, 0x40, 0x0, 0x1f, 0xff,
    0xff, 0x80, 0x0, 0x0, 0x1b, 0xff, 0x80, 0x0,

    /* U+0037 "7" */
    0x7f, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xe7, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x15,
    0x55, 0x55, 0x55, 0x7f, 0xf0, 0x0, 0x0, 0x0,
    0x2, 0xff, 0x80, 0x0, 0x0, 0x0, 0xf, 0xfc,
    0x0, 0x0, 0x0, 0x0, 0x7f, 0xe0, 0x0, 0x0,
    0x0, 0x3, 0xff, 0x0, 0x0, 0x0, 0x0, 0x1f,
    0xfc, 0x0, 0x0, 0x0, 0x0, 0xff, 0xd0, 0x0,
    0x0, 0x0, 0x7, 0xff, 0x0, 0x0, 0x0, 0x0,
    0x2f, 0xf4, 0x0, 0x0, 0x0, 0x0, 0xff, 0xc0,
    0x0, 0x0, 0x0, 0xb, 0xfe, 0x0, 0x0, 0x0,
    0x0, 0x3f, 0xf0, 0x0, 0x0, 0x0, 0x2, 0xff,
    0x80, 0x0, 0x0, 0x0, 0xf, 0xfd, 0x0, 0x0,
    0x0, 0x0, 0x7f, 0xf0, 0x0, 0x0, 0x0, 0x3,
    0xff, 0x40, 0x0, 0x0, 0x0, 0x1f, 0xfc, 0x0,
    0x0, 0x0, 0x0, 0xff, 0xe0, 0x0, 0x0, 0x0,
    0x7, 0xff, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xf8,
    0x0, 0x0, 0x0, 0x1, 0xff, 0xc0, 0x0, 0x0,
    0x0, 0xb, 0xff, 0x0, 0x0, 0x0, 0x0, 0x3f,
    0xf4, 0x0, 0x0, 0x0, 0x2, 0xff, 0xc0, 0x0,
    0x0, 0x0, 0xf, 0xfd, 0x0, 0x0, 0x0, 0x0,
    0xbf, 0xf0, 0x0, 0x0, 0x0, 0x3, 0xff, 0x80,
    0x0, 0x0, 0x0, 0x1f, 0xfc, 0x0, 0x0, 0x0,

    /* U+0038 "8" */
    0x0, 0x6, 0xff, 0xe4, 0x0, 0x0, 0x7, 0xff,
    0xff, 0xf8, 0x0, 0x2, 0xff, 0xff, 0xff, 0xf0,
    0x0, 0x7f, 0xff, 0xff, 0xff, 0xc0, 0xf, 0xff,
    0xd5, 0xbf, 0xfe, 0x2, 0xff, 0xe0, 0x0, 0xff,
    0xf0, 0x3f, 0xfc, 0x0, 0x7, 0xff, 0x43, 0xff,
    0x40, 0x0, 0x3f, 0xf4, 0x3f, 0xf4, 0x0, 0x3,
    0xff, 0x83, 0xff, 0x40, 0x0, 0x3f, 0xf4, 0x2f,
    0xf8, 0x0, 0x3, 0xff, 0x1, 0xff, 0xd0, 0x0,
    0xbf, 0xf0, 0xb, 0xff, 0x80, 0x7f, 0xfc, 0x0,
    0x2f, 0xff, 0xff, 0xff, 0x40, 0x0, 0x7f, 0xff,
    0xff, 0xc0, 0x0, 0x7, 0xff, 0xff, 0xf8, 0x0,
    0x2, 0xff, 0xff, 0xff, 0xf4, 0x0, 0xff, 0xf9,
    0x5b, 0xff, 0xd0, 0x2f, 0xfd, 0x0, 0xb, 0xff,
    0x3, 0xff, 0x40, 0x0, 0x3f, 0xf8, 0x7f, 0xf0,
    0x0, 0x1, 0xff, 0xcb, 0xfe, 0x0, 0x0, 0xf,
    0xfc, 0xbf, 0xe0, 0x0, 0x0, 0xff, 0xcb, 0xfe,
    0x0, 0x0, 0xf, 0xfc, 0xbf, 0xf0, 0x0, 0x1,
    0xff, 0xc7, 0xff, 0x40, 0x0, 0x3f, 0xfc, 0x3f,
    0xfc, 0x0, 0xb, 0xff, 0x81, 0xff, 0xf9, 0x17,
    0xff, 0xf0, 0xf, 0xff, 0xff, 0xff, 0xfd, 0x0,
    0x3f, 0xff, 0xff, 0xff, 0x40, 0x0, 0x7f, 0xff,
    0xff, 0xc0, 0x0, 0x0, 0x6f, 0xfe, 0x80, 0x0,

    /* U+0039 "9" */
    0x0, 0x6, 0xff, 0xe0, 0x0, 0x0, 0x1f, 0xff,
    0xff, 0x80, 0x0, 0x2f, 0xff, 0xff, 0xfc, 0x0,
    0x2f, 0xff, 0xff, 0xff, 0xc0, 0xf, 0xff, 0x95,
    0xff, 0xf8, 0xf, 0xff, 0x40, 0xb, 0xff, 0x43,
    0xff, 0x40, 0x0, 0xff, 0xe2, 0xff, 0xc0, 0x0,
    0xf, 0xfc, 0xbf, 0xe0, 0x0, 0x3, 0xff, 0x7f,
    0xf4, 0x0, 0x0, 0xbf, 0xef, 0xfd, 0x0, 0x0,
    0x1f, 0xfb, 0xff, 0x40, 0x0, 0x7, 0xff, 0xff,
    0xe0, 0x0, 0x1, 0xff, 0xef, 0xfc, 0x0, 0x0,
    0x7f, 0xf7, 0xff, 0x0, 0x0, 0x3f, 0xfc, 0xff,
    0xf0, 0x0, 0x3f, 0xff, 0x2f, 0xff, 0x40, 0x7f,
    0xff, 0xc3, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x7f,
    0xff, 0xff, 0xff, 0xf8, 0x3, 0xff, 0xff, 0xdb,
    0xfd, 0x0, 0x1b, 0xff, 0x43, 0xff, 0x0, 0x0,
    0x0, 0x0, 0xff, 0xc0, 0x0, 0x0, 0x0, 0x7f,
    0xe0, 0x0, 0x0, 0x0, 0x3f, 0xf4, 0x0, 0x0,
    0x0, 0x2f, 0xfc, 0x0, 0x0, 0x0, 0x2f, 0xfd,
    0x0, 0x0, 0x0, 0x7f, 0xfe, 0x0, 0x0, 0x5a,
    0xff, 0xff, 0x0, 0x0, 0x7f, 0xff, 0xff, 0x0,
    0x0, 0x1f, 0xff, 0xfe, 0x0, 0x0, 0x7, 0xff,
    0xf8, 0x0, 0x0, 0x1, 0xff, 0x90, 0x0, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 409, .box_w = 22, .box_h = 32, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 176, .adv_w = 409, .box_w = 14, .box_h = 32, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 288, .adv_w = 409, .box_w = 23, .box_h = 32, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 472, .adv_w = 409, .box_w = 22, .box_h = 32, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 648, .adv_w = 409, .box_w = 24, .box_h = 32, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 840, .adv_w = 409, .box_w = 22, .box_h = 32, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1016, .adv_w = 409, .box_w = 22, .box_h = 32, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1192, .adv_w = 409, .box_w = 23, .box_h = 32, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1376, .adv_w = 409, .box_w = 22, .box_h = 32, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1552, .adv_w = 409, .box_w = 21, .box_h = 32, .ofs_x = 2, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 48, .range_length = 10, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 2,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t ui_font_Roboto45 = {
#else
lv_font_t ui_font_Roboto45 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 32,          /*The maximum line height required by the font*/
    .base_line = 0,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -3,
    .underline_thickness = 2,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if UI_FONT_ROBOTO45*/

