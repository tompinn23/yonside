#pragma once

#include "config.h"

#include <stdint.h>

struct YON_ConsoleTile {
	int ch;
	uint32_t fg;
	uint32_t bg;
};

struct YON_Console {
	int w, h;
	uint32_t fg, bg;
	struct YON_ConsoleTile* tiles;
	int elements;
	
	int id;
};

typedef struct YON_ConsoleTile YON_ConsoleTile;
typedef struct YON_Console YON_Console;


YON_PUBLIC YON_Console* YON_Console_new(int w, int h);
YON_PUBLIC void YON_Console_delete(YON_Console* con);
YON_PUBLIC int YON_Console_get_width(const YON_Console* con);
YON_PUBLIC int YON_Console_get_height(const YON_Console* con);
YON_PUBLIC void YON_Console_blit(const YON_Console* src,
	int srcX,
	int srcY,
	int srcW,
	YON_Console* dst,
	int dstX,
	int dstY);

YON_PUBLIC void YON_Console_delete(YON_Console* con);
YON_PUBLIC void YON_Console_set_bkgrnd(YON_Console* con, uint32_t* col);
YON_PUBLIC void YON_Console_set_fgrnd(YON_Console* con, uint32_t* col);

YON_PUBLIC void YON_Console_set_fgrnd_char(YON_Console* con, int x, int y, uint32_t* col);
YON_PUBLIC void YON_Console_set_bkgrnd_char(YON_Console* con, int x, int y, uint32_t* col);
YON_PUBLIC void YON_Console_set_char(YON_Console* con, int x, int y, int ch);
