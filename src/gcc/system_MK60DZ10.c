/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,野火科技
 *     All rights reserved.
 *     技术讨论：野火初学论坛 http://www.chuxue123.com
 *
 *     除注明出处外，以下所有内容版权均属野火科技所有，未经允许，不得用于商业用途，
 *     修改内容时必须保留野火科技的版权声明。
 *
 * @file       system_MK60DZ10.c
 * @brief      系统启动相关函数
 * @author     野火科技
 * @version    v5.0
 * @date       2013-07-02
 */

#include "common.h"
//#include "system_MK60DZ10.h"
#include "MK60_uart.h"
#include "MK60_wdog.h"



int core_clk_khz;
int core_clk_mhz;
int bus_clk_khz;

//extern void main(void);

/*!
 *  @brief      系统初始化，设置系统频率，初始化printf端口
 *  @since      v5.0
 *  @note       此函数是系统启动初期由汇编函数调用，然后执行main函数
 */
void __init_user(void)
{
    core_clk_mhz = pll_init(CORE_CLK);     //设置系统时钟
    //core_clk_mhz = 20;     //设置系统时钟

    core_clk_khz = core_clk_mhz * 1000;     //把配置好的时钟都保存在全局变量里，以便后续使用
    bus_clk_khz = core_clk_khz / (((SIM_CLKDIV1 & SIM_CLKDIV1_OUTDIV2_MASK) >> 24) + 1);

    //uart_init (FIRE_PORT, FIRE_BAUD);   //初始化printf用到的管脚
}

/*!
 *  @brief      trace 时钟输出 初始化
 *  @since      v5.0
 *  @note       可用来校验时钟输出是否正确
 *  @author     飞思卡尔公司
 */
void trace_clk_init(void)
{
    /* Set the trace clock to the core clock frequency */
    SIM_SOPT2 |= SIM_SOPT2_TRACECLKSEL_MASK;

    /* Enable the TRACE_CLKOUT pin function on PTA6 (alt7 function) */
    PORTA_PCR6 = ( PORT_PCR_MUX(0x7));
}

/*!
 *  @brief      fb 时钟输出 初始化
 *  @since      v5.0
 *  @note       可用来校验时钟输出是否正确
 *  @author     飞思卡尔公司
 */
void fb_clk_init(void)
{
    /* Enable the clock to the FlexBus module */
    SIM_SCGC7 |= SIM_SCGC7_FLEXBUS_MASK;

    /* Enable the FB_CLKOUT function on PTC3 (alt5 function) */
    PORTC_PCR3 = ( PORT_PCR_MUX(0x5));
}
