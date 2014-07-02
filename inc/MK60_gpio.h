/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,野火科技
 *     All rights reserved.
 *     技术讨论：野火初学论坛 http://www.chuxue123.com
 *
 *     除注明出处外，以下所有内容版权均属野火科技所有，未经允许，不得用于商业用途，
 *     修改内容时必须保留野火科技的版权声明。
 *
 * @file       MK60_gpio.h
 * @brief      gpio驱动头文件
 * @author     野火科技
 * @version    v5.0
 * @date       2013-06-26
 */
#ifndef __MK60_GPIO_H__
#define __MK60_GPIO_H__

#ifdef __cplusplus
	extern "C" {
#endif

#include <stdint.h>
#include "mini_common.h"
#include "MK60_gpio_cfg.h"

/*
 * 定义管脚方向
 */
typedef enum GPIO_CFG
{
    //这里的值不能改！！！
    GPI         = 0,                                //定义管脚输入方向      GPIOx_PDDRn里，0表示输入，1表示输出
    GPO         = 1,                                //定义管脚输出方向
} GPIO_CFG;

//#define HIGH  1u
//#define LOW   0u

extern  GPIO_MemMapPtr      GPIOX[PTX_MAX];
#define GPIOX_BASE(PTxn)    GPIOX[PTX(PTxn)]       //GPIO模块的地址


/****************************外部使用****************************/

extern void    gpio_init  (PTXn_e, GPIO_CFG, uint8_t data);    //初始化gpio
/*
extern void    gpio_ddr   (PTXn_e, GPIO_CFG);                //设置引脚数据方向
extern void    gpio_set   (PTXn_e,           uint8 data);    //设置引脚状态
extern void    gpio_turn  (PTXn_e);                          //反转引脚状态
extern uint8   gpio_get   (PTXn_e);                          //读取引脚状态
*/

/*!
 *  @brief      设置引脚数据方向
 *  @param      PTxn    端口
 *  @param      cfg     引脚方向,0=输入,1=输出
 *  @since      v5.0
 *  Sample usage:       gpio_ddr (PTA8, GPI);    //设置 PTA8 管脚为输入
 */
inline void gpio_ddr(const PTXn_e ptxn, const GPIO_CFG cfg)
{
    //端口方向控制输入还是输出
    if (cfg == GPI)
    {
        //设置端口方向为输入
        GPIO_PDDR_REG(GPIOX_BASE(ptxn)) &= ~(1 << PTn(ptxn));           // GPIO PDDR 管脚号 清0，即对应管脚配置为端口方向输入
    }
    else
    {
        //设置端口方向为输出
        GPIO_PDDR_REG(GPIOX_BASE(ptxn)) |= (1 << PTn(ptxn));            // GPIO PDDR 管脚号 置1，即对应管脚配置为端口方向输出
    }
}

/*!
 *  @brief      设置引脚状态
 *  @param      PTxn    端口
 *  @param      data    输出初始状态,0=低电平,1=高电平 （对输入无效）
 *  @since      v5.0
 *  @warning    务必保证数据方向为输出（DEBUG模式下，有断言进行检测）
 *  Sample usage:       gpio_set (PTA8, 1);    // PTA8 管脚 输出 1
 */
inline void gpio_set(const PTXn_e ptxn, const uint8_t data)
{
	// 断言，检测 输出方向是否为输出
	// 获取 GPIO PDDR 管脚号 ，比较是否为输出
    ASSERT( BIT_GET( GPIO_PDDR_REG(GPIOX_BASE(ptxn)) , PTn(ptxn)) == GPO );
    //端口输出数据
    if (data == 0)
    {
        GPIO_PDOR_REG(GPIOX_BASE(ptxn)) &= ~(1 << PTn(ptxn));   // GPIO PDOR 管脚号 清0，即对应管脚配置为端口输出低电平
    }
    else
    {
        GPIO_PDOR_REG(GPIOX_BASE(ptxn))  |= (1 << PTn(ptxn));   // GPIO PDOR 管脚号 置1，即对应管脚配置为端口输出高电平
    }
}

/*!
 *  @brief      反转引脚状态
 *  @param      PTxn    端口
 *  @since      v5.0
 *  @warning    务必保证数据方向为输出（DEBUG模式下，有断言进行检测）
 *  Sample usage:       gpio_turn (PTA8);    // PTA8 管脚 输出 反转
 */
inline void gpio_turn(const PTXn_e ptxn)
{
	// 断言，检测 输出方向是否为输出
	// 获取 GPIO PDDR 管脚号 ，比较是否为输出
    ASSERT( BIT_GET( GPIO_PDDR_REG(GPIOX_BASE(ptxn)) , PTn(ptxn)) == GPO );
    // GPIO PTOR ptxn 置1，其他清0 ，即对应管脚配置为端口输出反转，其他位不变
    // 此处不能用 BIT_SET 这个宏来置1 ，因为必须保证其他位 不变，其他位直接清0即可
    GPIO_PTOR_REG( GPIOX_BASE(ptxn))  =  1 << (PTn(ptxn ));
}

/*!
 *  @brief      读取引脚输入状态
 *  @param      PTxn    端口
 *  @return     管脚的状态，1为高电平，0为低电平
 *  @since      v5.0
 *  @warning    务必保证数据方向为输入（DEBUG模式下，有断言进行检测）
 *  Sample usage:       uint8 pta8_data = gpio_get (PTA8);    // 获取 PTA8 管脚 输入电平
 */
inline uint8_t gpio_get(const PTXn_e ptxn)
{
	// 断言，检测 输出方向是否为输入
	// 获取 GPIO PDDR 管脚号 ，比较是否为输入
    ASSERT( BIT_GET( GPIO_PDDR_REG(GPIOX_BASE(ptxn)) , PTn(ptxn)) == GPI );
    // 获取 GPIO PDIR ptxn 状态，即读取管脚输入电平
    return ((GPIO_PDIR_REG(GPIOX_BASE(ptxn)) >> PTn(ptxn )) & 0x01);
}



//如下 4个 函数 的 PTxn 只能是 宏定义，不能是 变量
#define GPIO_SET(PTxn,data)       (PTXn_T(PTxn,OUT)= (data))    //设置输出电平
#define GPIO_TURN(PTxn)           (PTXn_T(PTxn,T)= 1)           //翻转输出电平
#define GPIO_GET(PTxn)            (PTXn_T(PTxn,IN))             //读取引脚输入状态
#define GPIO_DDR(PTxn,ddr)        (PTXn_T(PTxn,DDR) = ddr)      //输入输出状态


//如下  函数 的 PTxn 可以是  宏定义，也可以是 变量


//n位操作
#define GPIO_SET_NBIT(NBIT,PTxn,data)   GPIO_PDOR_REG(GPIOX_BASE(PTxn)) =   (                                                   \
                                                                                (                                               \
                                                                                    GPIO_PDOR_REG(GPIOX_BASE(PTxn))             \
                                                                                    &                                           \
                                                                                    ((uint32)( ~(((1<<NBIT)-1)<<PTn(PTxn))))    \
                                                                                )                                               \
                                                                                |   ((data)                                     \
                                                                                    &(                                          \
                                                                                        ((1<<NBIT)-1)                           \
                                                                                            <<PTn(PTxn)                         \
                                                                                     ))                                         \
                                                                            )


#define GPIO_DDR_NBIT(NBIT,PTxn,ddr)   GPIO_PDDR_REG(GPIOX_BASE(PTxn))  =   (                                                   \
                                                                                (                                               \
                                                                                    GPIO_PDDR_REG(GPIOX_BASE(PTxn))             \
                                                                                    &                                           \
                                                                                    ((uint32)( ~(((1<<NBIT)-1)<<PTn(PTxn))))    \
                                                                                )                                               \
                                                                                |   ((ddr)                                      \
                                                                                    &(                                          \
                                                                                        ((1<<NBIT)-1)                           \
                                                                                        <<PTn(PTxn)                             \
                                                                                    ))                                          \
                                                                            )

#define GPIO_T_NBIT(NBIT,PTxn,data)   GPIO_PTOR_REG(GPIOX_BASE(PTxn))  =   (                                                    \
                                                                                (                                               \
                                                                                    GPIO_PTOR_REG(GPIOX_BASE(PTxn))             \
                                                                                    &                                           \
                                                                                    ((uint32)( ~(((1<<NBIT)-1)<<PTn(PTxn))))    \
                                                                                )                                               \
                                                                                |   ((data)                                     \
                                                                                    &(                                          \
                                                                                        ((1<<NBIT)-1)                           \
                                                                                        <<PTn(PTxn)                             \
                                                                                    ))                                          \
                                                                            )


#define GPIO_GET_NBIT(NBIT,PTxn)    (( GPIO_PDIR_REG(GPIOX_BASE(PTxn))>>PTn(PTxn) ) & ((1<<NBIT)-1))

#ifdef __cplusplus
	}
#endif

#endif      //__MK60_GPIO_H__
