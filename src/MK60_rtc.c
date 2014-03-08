/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,野火科技
 *     All rights reserved.
 *     技术讨论：野火初学论坛 http://www.chuxue123.com
 *
 *     除注明出处外，以下所有内容版权均属野火科技所有，未经允许，不得用于商业用途，
 *     修改内容时必须保留野火科技的版权声明。
 *
 * @file       MK60_rtc.c
 * @brief      rtc模块函数
 * @author     野火科技
 * @version    v5.0
 * @date       2013-06-29
 */


#include "common.h"
#include "MK60_rtc.h"

/*!
 *  @brief      RTC初始化
 *  @since      v5.0
 *  Sample usage:       rtc_init();    //RTC初始化
 */
void rtc_init(void)
{
    volatile uint32 delay;

    SIM_SCGC6 |= SIM_SCGC6_RTC_MASK;    //开启 RTC 时钟

    RTC_CR  = RTC_CR_SWR_MASK;          //复位 RTC 寄存器（除 SWR， RTC_WAR ， RTC_RAR ）
    RTC_CR  &= ~RTC_CR_SWR_MASK;        //清空复位标志位
    RTC_CR  = (0
               | RTC_CR_OSCE_MASK       //32.768 kHz 晶振 使能
               //| RTC_CR_SC2P_MASK     //加入 2p 电容
               //| RTC_CR_SC4P_MASK     //加入 4p 电容
               //| RTC_CR_SC8P_MASK     //加入 8p 电容
               | RTC_CR_SC16P_MASK      //加入 16p 电容
               | RTC_CR_CLKO_MASK       //RTC_CLKOUT 输出 32k 使能 (0表示输出，1表示禁止)
              );

    delay = 0x600000;
    while(delay--);                     //等待 32K 晶振稳定（起振时间需要看晶振手册）

    //设置时间补偿
    RTC_TCR = (0
               | RTC_TCR_CIR(0)         //补偿间隔(可以从1秒(0X0)到256(0xFF)的范围内),8bit
               | RTC_TCR_TCR(0)         //补偿值的范围从 32*1024Hz -127 的周期到 32*1024Hz +128 周期，即 TCR 范围为 (int8)-127 ~ (int8)128
              );

    RTC_SR &= RTC_SR_TCE_MASK;          //禁用RTC 计数器，便于后续设置寄存器  TSR 和 TPR

    //时间和闹钟设置
    RTC_TSR = 0;                        //当前时间
    RTC_TAR = 0;                        //闹钟时间

    //中断配置
    RTC_IER = (0
               //| RTC_IER_TAIE_MASK    //闹钟中断使能（0表示禁止，1表示使能）
               //| RTC_IER_TOIE_MASK    //溢出中断使能（0表示禁止，1表示使能）
               //| RTC_IER_TIIE_MASK    //无效时间中断使能（0表示禁止，1表示使能）
              );

    RTC_SR |= RTC_SR_TCE_MASK;          //使能RTC 计数器
}

/*!
 *  @brief      设置当前时间
 *  @since      v5.0
 */
void rtc_set_time(uint32 seconds)
{
    RTC_SR &= ~RTC_SR_TCE_MASK;          //禁用RTC 计数器，便于后续设置寄存器  TSR 和 TPR
    RTC_TSR = seconds;                     //当前时间
    RTC_SR |= RTC_SR_TCE_MASK;          //使能RTC 计数器

}

/*!
 *  @brief      获取当前时间
 *  @since      v5.0
 */
uint32 rtc_get_time(void)
{
    return RTC_TSR;
}


/*!
 *  @brief      设置RTC闹钟时间，使能闹钟中断
 *  @param      alarm    闹钟时间
 *  @return     设置闹钟结果(0表示失败，1表示成功)
 *  @since      v5.0
 *  Sample usage:       if( rtc_set_alarm(sec) == 0 )       //设置闹钟时间 为 sec
                        {
                            printf("\n设置闹钟失败，不能设置过去的时间为闹钟时间!");
                        }
 */
uint8 rtc_set_alarm(uint32 alarm)
{
    if(alarm < RTC_TSR)                 //闹钟时间不能为过去时间
    {
        return 0;
    }

    RTC_SR &= ~RTC_SR_TCE_MASK;         //禁用RTC 计数器，便于后续设置寄存器  TSR 和 TPR

    RTC_TAR = alarm;                    //闹钟时间
    RTC_SR |= RTC_SR_TCE_MASK;          //使能RTC 计数器

    RTC_IER |= RTC_IER_TAIE_MASK;       //使能闹钟中断

    return 1;
}

/*!
 *  @brief      关闭闹钟中断
 *  @since      v5.0
 */
void rtc_close_alarm()
{
    RTC_IER &= ~RTC_IER_TAIE_MASK;      //禁止闹钟中断
}



