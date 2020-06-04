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
			#endif
		#else
			#ifdef __GNUC__
				#define YON_API __attribute__((dllimport))
			#else
				#define YON_API __declspec(dllimport)
			#endif

