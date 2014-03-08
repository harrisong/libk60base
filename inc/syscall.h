/*
 * syscall.h
 *
 *  Created on: 2 Feb 2014
 *      Author: Ming
 */

#ifndef LIBBASE_SYSCALL_H_
#define LIBBASE_SYSCALL_H_

#ifdef __cplusplus
	extern "C" {
#endif

typedef int (*FwriteHandler)(int file, char *ptr, int len);
extern FwriteHandler __g_fwrite_handler;

#ifdef __cplusplus
	}
#endif

#endif /* LIBBASE_SYSCALL_H_ */
