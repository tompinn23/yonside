#pragma once

#include "config.h"

struct SDL_Window;
struct SDL_Renderer;
struct YON_Console;
struct YON_Tileset;

struct YON_Context {
	struct SDL_Window* window;
	struct SDL_Renderer* renderer;
	struct YON_Console* root;
	struct YON_Tileset* default_tileset;
	int (*render)(struct YON_Context* self, struct YON_Console* con);
};

typedef struct YON_Context YON_Context;

YON_Context* YON_Context_new();
