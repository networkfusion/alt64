//
// Copyright (c) 2019 The Altra64 project contributors
// See LICENSE file in the project root for full license information.
//

#ifndef _IMAGE_H
#define	_IMAGE_H

// enable palette (tlut)
#define EN_TLUT 0x00800000000000

// enable atomic prim, 1st primitive bandwidth save
#define ATOMIC_PRIM 0x80000000000000

// enable perspective correction
#define PERSP_TEX_EN 0x08000000000000

// select alpha dither
#define ALPHA_DITHER_SEL_PATTERN 0x00000000000000
#define ALPHA_DITHER_SEL_PATTERNB 0x00001000000000
#define ALPHA_DITHER_SEL_NOISE 0x00002000000000
#define ALPHA_DITHER_SEL_NO_DITHER 0x00003000000000

// select rgb dither
#define RGB_DITHER_SEL_MAGIC_SQUARE_MATRIX 0x00000000000000
#define RGB_DITHER_SEL_STANDARD_BAYER_MATRIX 0x00004000000000
#define RGB_DITHER_SEL_NOISE 0x00008000000000
#define RGB_DITHER_SEL_NO_DITHER 0x0000C000000000

// enable texture filtering
#define SAMPLE_TYPE 0x00200000000000


sprite_t *loadImage32DFS(char *fname);
sprite_t *loadImageDFS(char *fname);
sprite_t *loadImage32(u8 *tbuf, int size);
void drawImage(display_context_t dcon, sprite_t *sprite);

#endif
