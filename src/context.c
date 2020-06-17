#include "context.h"

#include "quiteron.h"
#include "z_memory.h"
#include "log.h"

#include <stddef.h>
#include <SDL2/SDL.h>

static int sdl_init = 0;


YON_Context* YON_Context_new() {
	YON_Context* ctx = mem_alloc(sizeof(YON_Context));
	if(sdl_init != 0) {
		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS) < 0) {
			log_error("Failed to init SDL: %s", SDL_GetError());	
			return NULL;
		}
		ctx->window = SDL_CreateWindow("Yonside", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, NULL);
		if(!ctx->window) {
			log_error("Failed to create window: %s", SDL_GetError());
			return NULL;
		}
		ctx->renderer = SDL_CreateRenderer(ctx->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
		if(!ctx->renderer) {
			log_error("Failed to create renderer: %s", SDL_GetError());
			return NULL;
		}
		ctx->default_tileset = NULL;
		ctx->root = NULL;
	}
	return NULL;
}
