#pragma once

#include "config.h"

#include "log.h"

void YON_LogError(int LEVEL);


YON_FORMAT(1, 2) int YON_SetError(const char* error_msg, ...);
const char* YON_GetError();
