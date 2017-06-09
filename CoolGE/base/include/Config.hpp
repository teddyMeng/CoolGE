#ifndef _COOLGE_CONFIG
#define _COOLGE_CONFIG


#pragma once

#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
	#define COOLGE_PLATFORM_WINDOWS
	#if defined(_WIN64)
		#define COOLGE_PLATFORM_WIN64
	#else
		#define COOLGE_PLATFORM_WIN32
	#endif
#endif

#define COOLGE_EXPORT (extern "C" __dllexport)
#define _OPENGL


#endif
