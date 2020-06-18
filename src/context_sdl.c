#include "context.h"

#include "z_memory.h"
#include "terminal.h"
#include "map.h"

#include "SDL2/SDL.h"

#define DEFAULT_TERM_CACHE 16

typedef map_t(SDL_Texture*) sdl_tex_map_t;


struct SDL2_Renderer {
	SDL_Texture** layers;
};

