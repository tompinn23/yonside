#include "tileset.h"

#include "map.h"
#include "lodepng.h"
#include "log.h"
#include "z_memory.h"

#include "errno.h"
#include "stdlib.h"
#include "stdio.h"

typedef map_t(YON_Tileset*) YON_Tileset_map_t;

struct YON_TilesetRegistry
{
    YON_Tileset_map_t set_map;
};


static struct YON_TilesetRegistry* registry = NULL;

int YON_Tileset_init_reg() {
    if(registry != NULL)
        return 1;
    registry = mem_alloc(sizeof(struct YON_TilesetRegistry));
    map_init(&registry->set_map);
    return 1;
}

int YON_Tileset_loadf(const char* file, YON_TileLayout layout) {
    return YON_Tileset_loadf_ex(file, layout, file);
}

int YON_Tileset_loadf_ex(const char* file, YON_TileLayout layout, const char* key) {
    FILE* fp = fopen(file, "rb");
    fseek(fp, 0, SEEK_END);
    long fsz = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    uint8_t* buf = mem_alloc(fsz);
    long status;
    if((status = fread(buf, 1, fsz, fp)) != fsz) {
        if(feof(fp)) {
            YON_log_warn("Encountered EOF of file before expected. If error occurs file is corrupted: %s", file);
        }
        else if (ferror(fp) != 0) {
            YON_log_error("Failed to read file: %s, %s", file,  strerror(errno));
            return -1;
        }
    }
    return YON_Tileset_load(key, buf, layout);
}
int YON_Tileset_load(const char* key, uint8_t* memory, YON_TileLayout layout) {
    YON_Tileset* tileset = mem_alloc(sizeof(YON_Tileset));
    uint8_t* buffer;
    unsigned w, h, error;
    error = lodepng_decode32(&buffer, &w, &h, memory, SZ(memory));
    if(error) {
        YON_log_error("Failed to decode png: %s", lodepng_error_text(error));
        return -1;
    }
    tileset->tiles = buffer;
    tileset->codepoints = mem_alloc(256 * sizeof(int));
    switch(layout) {
        case LAYOUT_INROW:
            tileset->width = w / 16;
            tileset->height = h / 16;
            for(int i = 0; i < 256; i++) {
                tileset->codepoints[i] = i * w * h * 4;
            }
            break;
        case LAYOUT_INCOL:
            tileset->width = w / 16;
            tileset->height = h / 16;
    }
}