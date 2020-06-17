#pragma once

#include "stdint.h"

typedef enum {
    LAYOUT_INROW,
    LAYOUT_TCOD
} YON_TileLayout;

struct YON_Tileset {
    int width;
    int height;
    uint8_t* tiles;
    int* codepoints;
};

typedef struct YON_Tileset YON_Tileset;

int YON_Tileset_loadf(const char* file, YON_TileLayout layout);
int YON_Tileset_loadf_ex(const char* file, YON_TileLayout layout, const char* key);
int YON_Tileset_load(const char* key, uint8_t* memory, YON_TileLayout layout);

int YON_Tileset_remove(const char* key);
YON_Tileset* YON_Tileset_get(const char* key);
