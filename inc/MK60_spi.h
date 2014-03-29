/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,野火科技
 *     All rights reserved.
 *     技术讨论：野火初学论坛 http://www.chuxue123.com
 *
 *     除注明出处外，以下所有内容版权均属野火科技所有，未经允许，不得用于商业用途，
 *     修改内容时必须保留野火科技的版权声明。
 *
 * @file       MK60_spi.c
 * @brief      SPI驱动函数
 * @author     野火科技
 * @version    v5.0
 * @date       2013-07-16
 */
#ifndef __MK60_SPI_H__
#define __MK60_SPI_H__

#ifdef __cplusplus
	extern "C" {
#endif

//定义主从机模式
typedef enum
{
	MASTER,    //主机模式
	SLAVE      //主机模式
} SPI_CFG;

//定义SPI模块号
typedef enum
{
	SPI0,
	SPI1,
	SPI2
} SPIn_e;

//定义SPI模块片选号
typedef enum
{
	SPIn_PCS0 = 1 << 0,
	SPIn_PCS1 = 1 << 1,
	SPIn_PCS2 = 1 << 2,
	SPIn_PCS3 = 1 << 3,
	SPIn_PCS4 = 1 << 4,
	SPIn_PCS5 = 1 << 5,
} SPIn_PCSn_e;

#define SPI_MOSI_FLAG 0x1
#define SPI_MISO_FLAG 0x2


uint32 spi_init       (SPIn_e, SPIn_PCSn_e , SPI_CFG, uint8_t flag, uint32 baud);                                        //SPI初始化，设置模式

//主机接收发送函数
void spi_mosi       (SPIn_e spin, SPIn_PCSn_e pcs, const uint8_t *modata, uint8_t *midata, const uint32 len);    //SPI发送接收函数,发送databuff数据，并把接收到的数据存放在databuff里(注意，会覆盖原来的databuff)
void spi_mosi_cmd   (SPIn_e spin, SPIn_PCSn_e pcs, const uint8_t *mocmd , uint8_t *micmd , const uint8_t *modata, uint8_t *midata, const uint32 cmdlen , const uint32 len); //SPI发送接收函数,与spi_mosi相比，多了先发送cmd 缓冲区的步骤，即分开两部分发送

#ifdef __cplusplus
	}
#endif

#endif  // __MK60_SPI_H__
