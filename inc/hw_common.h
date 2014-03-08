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

#ifndef LIBBASE_HW_COMMON_H_
#define LIBBASE_HW_COMMON_H_

#ifdef __cplusplus
	extern "C" {
#endif

#include "vectors.h"

//这两个顺序不能反，因为 arm_math.h 里需要  __NVIC_PRIO_BITS 的定义
#define   __NVIC_PRIO_BITS    4       /*ARM Cortex M4 implementation for interrupt priority shift*/
//#include "arm_math.h"
#include "core_cm4.h"


/*
 * 包含野火K60平台的配置头文件
 */
#include "FIRE_MK60_conf.h"

/*
 * 包含平台头文件
 */
#if defined(MK60DZ10)
#include "kinetis/MK60DZ10.h"

#elif defined(MK60F15)
#include "kinetis/MK60F15.h"

//SIM_SCGC4_IIC2_MASK 改为 SIM_SCGC4_IIC0_MASK
//SIM_SCGC4_IIC2_SHIFT  改为 SIM_SCGC4_IIC0_SHIFT
#else
#error "error"
#endif



/*
 * 包含常用头文件
 */
#if defined(__GNUC__)
#include    "gcc/system_MK60DZ10.h"             //系统配置

#else
#include    "IAR/system_MK60DZ10.h"             //系统配置
#endif
#include    "FIRE_PORT_cfg.h"               //管脚复用配置
#include    "MK60_mcg.h"                    //K60 时钟模块

#ifdef __cplusplus
	}
#endif

#endif /* LIBBASE_HW_COMMON_H_ */
