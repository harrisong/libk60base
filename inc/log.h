/*
 * log.h
 *
 * Author: Ming
 */

#ifndef LIBBASE_LOG_H_
#define LIBBASE_LOG_H_

#include <stdio.h>

#define LOG_E(fmt, ...) iprintf("ERROR: " fmt "\n", ##__VA_ARGS__)
#define LOG_W(fmt, ...) iprintf("WARN: " fmt "\n", ##__VA_ARGS__)
#define LOG_I(fmt, ...) iprintf("INFO: " fmt "\n", ##__VA_ARGS__)
#ifdef DEBUG
	#define LOG_D(fmt, ...) iprintf("DEBUG: " fmt "\n", ##__VA_ARGS__)
	#define LOG_V(fmt, ...) iprintf("VERBOSE: " fmt "\n", ##__VA_ARGS__)
#else
	#define LOG_D(fmt, ...)
	#define LOG_V(fmt, ...)
#endif /* DEBUG */

#endif /* LIBBASE_LOG_H_ */