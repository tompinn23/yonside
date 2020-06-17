#include "errors.h"

static char error_str[256];

void YON_LogError(int LEVEL) {
    log_set_level(LEVEL);
}

int YON_SetError(const char* message, ...) {
    va_list args;
    va_start (args, message);
    vsnprintf(error_str, 256, message, args);
    va_end(args);
}

const char* YON_GetError() {
    return &error_str;
}