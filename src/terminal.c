#include "terminal.h"

#include "z_memory.h"

YON_Console* YON_Console_new(int w, int h) {
	YON_Console* con = mem_alloc(sizeof(YON_Console));
	con->w = w;
	con->h = h;
	con->tiles = mem_zalloc(sizeof(YON_ConsoleTile) * w * h);
	return con;
}

int YON_Console_get_width(const YON_Console* con) {
	return con->w;
}

int YON_Console_get_height(const YON_Console* con) {
	return con->h;
}

void YON_Console_blit(const YON_Console* src, int srcX, int srcY, int srcW, YON_Console* dst, int dstX, int dstY) {
	return;
}

void YON_Console_delete(YON_Console* con) {
	mem_free(con->tiles);
	mem_free(con);
}

void YON_Console_set_background(YON_Console* con, uint32_t col) {
	con->bg = col;
}

void YON_Console_set_foreground(YON_Console* con, uint32_t col) {
	con->fg = col;
}

void YON_Console_set_foreground_char(YON_Console* con, int x, int y, uint32_t col) {
	con->tiles[y * con->w + x].fg = col;
}

void YON_Console_set_background_char(YON_Console* con, int x, int y, uint32_t col) {
	con->tiles[y * con->w + x].bg = col;
}

void YON_Console_set_char(YON_Console* con, int x, int y, int ch) {
	con->tiles[y * con-> w + x].ch = ch;
}
