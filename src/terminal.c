#include "terminal.h"


YON_PUBLIC YON_Console* YON_Console_new(int w, int h)
{
	YON_Console* con = mem_alloc(sizeof(YON_Console));
	con->w = w;
	con->h = h;
	con->tiles = mem_zalloc(sizeof(YON_ConsoleTile) * w * h);
	return ;
}

YON_PUBLIC int YON_Console_get_width(const YON_Console* con)
{
	return con->w;
}

YON_PUBLIC int YON_Console_get_height(const YON_Console* con)
{
	return con->h;
}

YON_PUBLIC void YON_Console_blit(const YON_Console* src, int srcX, int srcY, int srcW, YON_Console* dst, int dstX, int dstY)
{
	return YON_PUBLIC void();
}

YON_PUBLIC void YON_Console_delete(YON_Console* con)
{
	return YON_PUBLIC void();
}

YON_PUBLIC void YON_Console_set_bkgrnd(YON_Console* con, uint32_t* col)
{
	return YON_PUBLIC void();
}

YON_PUBLIC void YON_Console_set_fgrnd(YON_Console* con, uint32_t* col)
{
	return YON_PUBLIC void();
}

YON_PUBLIC void YON_Console_set_fgrnd_char(YON_Console* con, int x, int y, uint32_t* col)
{
	return YON_PUBLIC void();
}

YON_PUBLIC void YON_Console_set_bkgrnd_char(YON_Console* con, int x, int y, uint32_t* col)
{
	return YON_PUBLIC void();
}

YON_PUBLIC void YON_Console_set_char(YON_Console* con, int x, int y, int ch)
{
	return YON_PUBLIC void();
}
