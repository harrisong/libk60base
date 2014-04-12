/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,野火科技
 *     All rights reserved.
 *     技术讨论：野火初学论坛 http://www.chuxue123.com
 *
 *     除注明出处外，以下所有内容版权均属野火科技所有，未经允许，不得用于商业用途，
 *     修改内容时必须保留野火科技的版权声明。
 *
 * @file       fire_port_cfg.h
 * @brief      野火K60 复用管脚配置
 * @author     野火科技
 * @version    v5.0
 * @date       2013-06-26
 */
#ifndef _FIRE_DRIVERS_CFG_H_
#define _FIRE_DRIVERS_CFG_H_

#include "MK60_port.h"

#ifdef __cplusplus
	extern "C" {
#endif

/**********************************  UART   ***************************************/

//      模块通道    端口          可选范围                          建议
#define UART0_RX    PTD6        //PTA1、PTA15、PTB16、PTD6          PTA1不要用（与Jtag冲突）
#define UART0_TX    PTD7        //PTA2、PTA14、PTB17、PTD7          PTA2不要用（与Jtag冲突）

#define UART1_RX    PTC3        //PTC3、PTE1
#define UART1_TX    PTC4        //PTC4、PTE0

#define UART2_RX    PTD2        //PTD2
#define UART2_TX    PTD3        //PTD3

#define UART3_RX    PTE5       //PTB10、PTC16、PTE5
#define UART3_TX    PTE4       //PTB11、PTC17、PTE4

#define UART4_RX    PTE25       //PTC14、PTE25
#define UART4_TX    PTE24       //PTC15、PTE24

#define UART5_RX    PTE9        //PTD8、PTE9
#define UART5_TX    PTE8        //PTD9、PTE8

/**********************************  FTM    ***************************************/

//      模块通道    端口          可选范围              建议
#define FTM0_CH0    PTC1        //PTC1、PTA3            PTA3不要用（与Jtag、SWD冲突）
#define FTM0_CH1    PTC2        //PTC2、PTA4
#define FTM0_CH2    PTC3        //PTC3、PTA5
#define FTM0_CH3    PTC4        //PTC4、PTA6
#define FTM0_CH4    PTD4        //PTD4、PTA7
#define FTM0_CH5    PTD5        //PTD5、PTA0            PTA0不要用（与Jtag、SWD冲突）
#define FTM0_CH6    PTD6        //PTD6、PTA1            PTA1不要用（与Jtag冲突）
#define FTM0_CH7    PTD7        //PTD7、PTA2            PTA2不要用（与Jtag冲突）


#if defined(K60_2014) || defined(K60_2014_GEN2) || defined(K60_2014_CAMERA)
	//      模块通道    端口          可选范围              建议
	#define FTM1_CH0    PTB0       //PTA8、PTA12、PTB0
	#define FTM1_CH1    PTB1       //PTA9、PTA13、PTB1

	//      模块通道    端口          可选范围              建议
	#define FTM2_CH0    PTB18       //PTA10、PTB18
	#define FTM2_CH1    PTB19       //PTA11、PTB19

#else
	#define FTM1_CH0    PTA8
	#define FTM1_CH1    PTA9

	#define FTM2_CH0    PTA10
	#define FTM2_CH1    PTA11
#endif


//正交解码模块通道  端口          可选范围              建议
#define FTM1_QDPHA  FTM1_CH0       //PTA8、PTA12、PTB0
#define FTM1_QDPHB  FTM1_CH1       //PTA9、PTA13、PTB1

#define FTM2_QDPHA  FTM2_CH0       //PTA10、PTB18
#define FTM2_QDPHB  FTM2_CH1       //PTA11、PTB19


/**********************************  I2C   ***************************************/

//      模块通道    端口          可选范围              建议
#define I2C0_SCL    PTD8        // PTB0、PTB2、PTD8
#define I2C0_SDA    PTD9        // PTB1、PTB3、PTD9

#define I2C1_SCL    PTC10       // PTE1、PTC10
#define I2C1_SDA    PTC11       // PTE0、PTC11


/**********************************  SPI   ***************************************/
//PCS接口，不用的时候需要注释，就不会进行初始化对应的管脚
//      模块通道    端口          可选范围                  建议

#define SPI0_SCK    PTA15       // PTA15、PTC5、PTD1        全部都是 ALT2
#define SPI0_SOUT   PTA16       // PTA16、PTC6、PTD2        全部都是 ALT2
#define SPI0_SIN    PTA17       // PTA17、PTC7、PTD3        全部都是 ALT2

#define SPI0_PCS0   PTA14       // PTA14、PTC4、PTD0、      全部都是 ALT2
#define SPI0_PCS1   PTC3        // PTC3、PTD4               全部都是 ALT2
#define SPI0_PCS2   PTC2        // PTC2、PTD5               全部都是 ALT2
#define SPI0_PCS3   PTC1        // PTC1、PTD6               全部都是 ALT2
#define SPI0_PCS4   PTC0        // PTC0、                   全部都是 ALT2
#define SPI0_PCS5   PTB23       // PTB23                    ALT3


#define SPI1_SCK    PTB11       // PTE2、PTB11、            全部都是 ALT2
#define SPI1_SOUT   PTB16       // PTE1、PTB16、            全部都是 ALT2
#define SPI1_SIN    PTB17       // PTE3、PTB17、            全部都是 ALT2

#define SPI1_PCS0   PTE4        // PTE4、PTB10、            全部都是 ALT2
#define SPI1_PCS1   PTE0        // PTE0、PTB9、             全部都是 ALT2
#define SPI1_PCS2   PTE5        // PTE5、                   全部都是 ALT2
#define SPI1_PCS3   PTE6        // PTE6、                   全部都是 ALT2


#define SPI2_SCK    PTB21       // PTB21、PTD12             全部都是 ALT2
#define SPI2_SOUT   PTB22       // PTB22、PTD13             全部都是 ALT2
#define SPI2_SIN    PTB23       // PTB23、PTD14             全部都是 ALT2
#define SPI2_PCS0   PTB20       // PTB20、PTD11             全部都是 ALT2
#define SPI2_PCS1   PTD15       // PTD15                    全部都是 ALT2


/**********************************  CAN   ***************************************/
#define CAN0_TX     PTA12       //PTA12、PTB18              全部都是 ALT2
#define CAN0_RX     PTA13       //PTA13、PTB19              全部都是 ALT2

#define CAN1_TX     PTE24       //PTE24、PTC17              全部都是 ALT2
#define CAN1_RX     PTE25       //PTE25、PTC16              全部都是 ALT2

#ifdef __cplusplus
	}
#endif

#endif  //_FIRE_DRIVERS_CFG_H_
