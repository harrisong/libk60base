/*
 * log.h
 *
 * Author: Ming
 */

#ifndef LIBBASE_LOG_H_
#define LIBBASE_LOG_H_

#include <stdio.h>

#define LOG_E(fmt, ...) printf("E " fmt "\n", ##__VA_ARGS__)
#define LOG_W(fmt, ...) printf("W " fmt "\n", ##__VA_ARGS__)
#define LOG_I(fmt, ...) printf("I " fmt "\n", ##__VA_ARGS__)
#ifdef DEBUG
	#define LOG_D(fmt, ...) printf("D " fmt "\n", ##__VA_ARGS__)
	#define LOG_V(fmt, ...) printf("V " fmt "\n", ##__VA_ARGS__)
#else
	#define LOG_D(fmt, ...)
	#define LOG_V(fmt, ...)
#endif /* DEBUG */

#endif /* LIBBASE_LOG_H_ */
