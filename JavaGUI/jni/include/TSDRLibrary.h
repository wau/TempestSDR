/*
#-------------------------------------------------------------------------------
# Copyright (c) 2014 Martin Marinov.
# All rights reserved. This program and the accompanying materials
# are made available under the terms of the GNU Public License v3.0
# which accompanies this distribution, and is available at
# http://www.gnu.org/licenses/gpl.html
# 
# Contributors:
#     Martin Marinov - initial API and implementation
#-------------------------------------------------------------------------------
*/
#ifndef _TSDRLibrary
#define _TSDRLibrary

	#include <stdint.h>

	#define FFT_SIZE_2048 (11)
	#define FFT_SIZE_1024 (10)
	#define FFT_SIZE_512 (9)
	#define FFT_SIZE_256 (8)

	// those PIXEL_* are only used for debugging purposes and
	// it is not required for the client to implement them
	#define PIXEL_SPECIAL_VALUE_R (256.0f)
	#define PIXEL_SPECIAL_VALUE_G (512.0f)
	#define PIXEL_SPECIAL_VALUE_B (1024.0f)
	#define PIXEL_SPECIAL_VALUE_TRANSPARENT (2048.0f)

	#define DIRECTION_CUSTOM (0)
	#define DIRECTION_UP (1)
	#define DIRECTION_DOWN (2)
	#define DIRECTION_LEFT (3)
	#define DIRECTION_RIGHT (4)

	#define PARAM_INT_AUTOPIXELRATE (0)
	#define PARAM_INT_AUTOSHIFT (1)
	#define COUNT_PARAM_INT (2)

	#define COUNT_PARAM_DOUBLE (2)

	typedef struct tsdr_lib tsdr_lib_t;

	typedef void(*tsdr_readasync_function)(float *buf, int width, int height, void *ctx);

	void tsdr_init(tsdr_lib_t ** tsdr);
	int tsdr_setbasefreq(tsdr_lib_t * tsdr, uint32_t freq);
	int tsdr_stop(tsdr_lib_t * tsdr);
	int tsdr_setgain(tsdr_lib_t * tsdr, float gain);
	int tsdr_readasync(tsdr_lib_t * tsdr, tsdr_readasync_function cb, void * ctx);
	int tsdr_loadplugin(tsdr_lib_t * tsdr, const char * pluginfilepath, const char * params);
	int tsdr_unloadplugin(tsdr_lib_t * tsdr);
	int tsdr_setresolution(tsdr_lib_t * tsdr, int width, int height, double refreshrate);
	int tsdr_isrunning(tsdr_lib_t * tsdr);
	int tsdr_sync(tsdr_lib_t * tsdr, int pixels, int direction);
	int tsdr_motionblur(tsdr_lib_t * tsdr, float coeff);
	void tsdr_free(tsdr_lib_t ** tsdr);
	char * tsdr_getlasterrortext(tsdr_lib_t * tsdr);
	int tsdr_setparameter_int(tsdr_lib_t * tsdr, int parameter, uint32_t value);
	int tsdr_setparameter_double(tsdr_lib_t * tsdr, int parameter, double value);

	// fft_size is the log2(size). i.e. if data is 1024, fft_size should be defined to 10
	int tsdr_getfft(tsdr_lib_t * tsdr, float * buffer, int fft_size, uint32_t * samplerate);

#endif
