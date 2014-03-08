/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,野火科技
 *     All rights reserved.
 *     技术讨论：野火初学论坛 http://www.chuxue123.com
 *
 *     除注明出处外，以下所有内容版权均属野火科技所有，未经允许，不得用于商业用途，
 *     修改内容时必须保留野火科技的版权声明。
 *
 * @file       system_MK60DZ10.h
 * @brief      系统启动相关函数
 * @author     野火科技
 * @version    v5.0
 * @date       2013-07-02
 */

#ifndef __SYSTEM_MK60_H__
#define __SYSTEM_MK60_H__

#ifdef __cplusplus
	extern "C" {
#endif

extern int core_clk_khz;
extern int core_clk_mhz;
extern int bus_clk_khz;


void clock_init(void);        //设置系统频率
void trace_clk_init(void);  //trace 时钟输出 初始化
void fb_clk_init(void);     //fb 时钟输出 初始化

#ifdef __cplusplus
	}
#endif

#endif  //__SYSTEM_MK60_H__
