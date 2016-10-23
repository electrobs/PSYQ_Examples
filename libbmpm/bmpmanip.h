/*
 *
 * functions to manipulate bitmaps.
 * 
 * This is for 15 bit RGB only (+1 for semiTrans, 16 bit total).
 * A1R5G5B5
 *
 */


#ifndef BMPMANIP_H
#define BMPMANIP_H

#include <stdint.h>

//sets semi trans bit in image data to one, use on any data, will detect bitmap and go to offset, or just start at beginning for raw data
int setSemiTrans(uint8_t *op_data, uint8_t red, uint8_t green, uint8_t blue, int len);

//clears SemiTransBit, use on any data
int clearSemiTrans(uint8_t *op_data, int len);

//convert bitmap data to RAW, if no header detected, or incorrect header, this does nothing.
//returns new size of data, 0 for no change, -1 for non-valid bitmap or realloc issue
int bitmapToRAW(uint8_t **op_data, int len);

//convert rgb data to bgr data, works with bitmap or 
//0 success, -1 failure
int swapRedBlue(uint8_t *op_data, int len);

#endif
