#pragma once

#ifndef YON_API
#ifdef YON_STATIC
#define YON_API
#elif defined _WIN32 || defined __CYGWIN__ || defined __MINGW32__
#ifdef YON_EXPORTS
#ifdef __GNUC__
#define YON_API __attribute__((dllexport))
#else
#define YON_API __declspec(dllexport)
#endif // __GNUC__
#else
#ifdef __GNUC__
#define YON_API __attribute__((dllimport))
#else
#define YON_API __declspec(dllimport)
#endif // __GNUC__
#endif // YON_EXPORTS
#elif __GNUC__ >= 4
#define YON_API __attribute__((visibility("default")))
#else
#define YON_API
#endif
#endif // YON_API

#define YON_PUBLIC YON_API


#ifdef __GNUC__
#define YON_FORMAT(str_index, first_arg) \
	__attribute__((format(printf, str_index, first_arg)))
#else
#define YON_FORMAT(str_index, first_arg)
#endif