/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,野火科技
 *     All rights reserved.
 *     技术讨论：野火初学论坛 http://www.chuxue123.com
 *
 *     除注明出处外，以下所有内容版权均属野火科技所有，未经允许，不得用于商业用途，
 *     修改内容时必须保留野火科技的版权声明。
 *
 * @file       common.h
 * @brief      野火K60 平台常用类型声明和宏定义
 * @author     野火科技
 * @version    v5.0
 * @date       2013-06-26
 */

#ifndef _COMMON_H_
#define _COMMON_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "mini_common.h"

#define TRUE    1
#define FALSE   0

/*
 * 定义坐标结构体
 */
/*
typedef struct
{
    uint16 x;
    uint16 y;
} Site_t;
*/

/*
 * 定义矩形大小结构体
 */
/*
typedef struct
{
    uint16 W;       //宽
    uint16 H;       //高
} Size_t;
*/


/*
 * 包含Cortex-M内核的通用头文件
 */
#include    <stdio.h>                       //printf
#include    <string.h>                      //memcpy
#include    <stdlib.h>                      //malloc
#include "misc.h"

#include "hw_common.h"


#if (defined(IAR))
#include "intrinsics.h"
#endif




/**
 *  @brief 变量的位清0和置1
 */
#define BIT_CLEAN(var,n)        (var) &= ~(1<<(n))   //变量var 的n位（即第n+1位）清0
#define BIT_SET(var,n)          (var) |=  (1<<(n))   //变量var 的n位（即第n+1位）置1
#define BIT_GET(var,n)          (((var)>>(n))&0x01)  //读取变量var 的n位（即第n+1位）

/**
 *  @brief 仿二进制赋值
 */
#define  HEX__(n)   0x##n##UL
#define  B8__(x)   ( (x & 0x0000000FUL) ? 1:0 )\
    +( (x & 0x000000F0UL) ? 2:0 )\
    +( (x & 0x00000F00UL) ? 4:0 )\
    +( (x & 0x0000F000UL) ? 8:0 )\
    +( (x & 0x000F0000UL) ? 16:0 )\
    +( (x & 0x00F00000UL) ? 32:0 )\
    +( (x & 0x0F000000UL) ? 64:0 )\
    +( (x & 0xF0000000UL) ? 128:0 )
#define  B8(x)                                     ((unsigned char)B8__(HEX__(x)))
#define  B16(x_msb,x_lsb)                (((unsigned int)B8(x_msb)<<8) + B8(x_lsb))
#define  B32(x_msb,x_2,x_3,x_lsb)   (((unsigned long)B8(x_msb)<<24) + ((unsigned long)B8(x_2)<<16) + ((unsigned long)B8(x_3)<<8) + B8(x_lsb))
/* Sample usage:
B8(01010101) = 85
B16(10101010,01010101) = 43605
B32(10000000,11111111,10101010,01010101) = 2164238933
*/


/*
 * 求最大值和最小值
 */
#define MAX( x, y ) ( ((x) > (y)) ? (x) : (y) )
#define MIN( x, y ) ( ((x) < (y)) ? (x) : (y) )


/*
 * 返回数组元素的个数
 */
#define ARR_SIZE( a ) ( sizeof( (a) ) / sizeof( ((a)[0]) ) )

/*
 * 宏定义实现返回绝对值（x里不能有自加自减的语句，否则变量出错）
 */
#define ABS(x) (((x) > 0) ? (x) : (-x))

/*
 * 获取结构体某成员偏移
 */
#define OFFSET(type, member)    (uint32)(&(((type *)0)->member))

/*
 * 确保x的范围为 min~max
 */
#define RANGE(x,max,min)        ((uint8)((x)<(min) ? (min) : ( (x)>(max) ? (max):(x) )))

/*
 * 交换32位数据的4字节顺序
 */
#define SWAP32(data)    (uint32)((((uint32)(data) & (0xFFu<<0 ))<<24)      \
                          | (((uint32)(data) & (0xFFu<<8 ))<<8)            \
                          | (((uint32)(data) & (0xFFu<<16))>>8)            \
                          | (((uint32)(data) & (0xFFu<<24))>>24)           \
                        )

/*
 * 交换16位数据的2字节顺序
 */
#define SWAP16(data)    (uint32)((((uint16)(data) & (0xFF<<0 ))<<8)      \
                          | (((uint32)(data) & (0xFF<<8))>>8)            \
                        )

/*
 * 交换 x, y 的值
 */
#define SWAP(x,y)           do{x^=y;y^=x;x^=y;}while(0)


#ifdef __cplusplus
}  /* extern "C" */
#endif
/********************************************************************/

#endif /* _COMMON_H_ */
