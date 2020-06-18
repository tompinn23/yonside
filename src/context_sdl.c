#include "context.h"

#include "z_memory.h"
#include "terminal.h"
#include "map.h"

#include "SDL2/SDL.h"

typedef map_t(SDL_Texture*) sdl_tex_map_t;


struct SDL2_RenderData {
    sdl_tex_map_t tile_cache;
    SDL_Texture** console_cache;
};


int sdl2_render_func(YON_Context* self, YON_Console* con) {
}


void YON_Context_set_renderer_sdl(YON_Context* ctx) {
    ctx->render = sdl2_render_func;
    ctx->__render_data = mem_alloc(sizeof(struct SDL2_RenderData));
}
