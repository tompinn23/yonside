/*
 * Copyright (c) 2017 rxi
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the MIT license. See `log.c` for details.
 */

#ifndef LOG_H
#define LOG_H

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdarg.h>

#define LOG_VERSION "0.1.0"
//#define LOG_USE_COLOR

typedef void(*log_LockFn)(void *udata, int lock);

enum { LOG_TRACE, LOG_DEBUG, LOG_INFO, LOG_WARN, LOG_ERROR, LOG_FATAL };

#if defined(BASE_FILE)
#define FF BASE_FILE
#else
#define FF __FILE__
#endif


#define log_trace(...) log_log(LOG_TRACE, FF, __LINE__, __VA_ARGS__)
#define log_debug(...) log_log(LOG_DEBUG, FF, __LINE__, __VA_ARGS__)
#define log_info(...)  log_log(LOG_INFO,  FF, __LINE__, __VA_ARGS__)
#define log_warn(...)  log_log(LOG_WARN,  FF, __LINE__, __VA_ARGS__)
#define log_error(...) log_log(LOG_ERROR, FF, __LINE__, __VA_ARGS__)
#define log_fatal(...) log_log(LOG_FATAL, FF, __LINE__, __VA_ARGS__)

void log_set_udata(void *udata);
void log_set_lock(log_LockFn fn);
void log_set_fp(FILE *fp);
void log_set_level(int level);
void log_set_quiet(int enable);

void log_log(int level, const char *file, int line, const char *fmt, ...);

void log_init();

#endif
