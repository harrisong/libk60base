/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,��火科���
 *     All rights reserved.
 *     ����讨论：��������学论����http://www.chuxue123.com
 *
 *     ��注��出处���，以下��������容��������属��������������������������许，���得用于���业用�����
 *     修改��容�����须������������������������声�������
 *
 * @file       MK60_adc.h
 * @brief      ADC��数
 * @author     ��火科���
 * @version    v5.0
 * @date       2013-08-28
 */


#ifndef __MK60_ADC_H__
#define __MK60_ADC_H__ 1

#ifdef __cplusplus
	extern "C" {
#endif

typedef enum
{
    // ---------------------------------ADC0-------------------------
    ADC0_DP0,
    ADC0_DP1,
    PGA0_DP,        //不支��ADC，���要������ADC PGA register 设置��大增���
    ADC0_DP3,
    //软件触���不支��B�����
    ADC0_SE4b,      // PTC2     不支��软件ADC
    ADC0_SE5b,      // PTD1     不支��软件ADC
    ADC0_SE6b,      // PTD5     不支��软件ADC
    ADC0_SE7b,      // PTD6     不支��软件ADC

    ADC0_SE8,       // PTB0
    ADC0_SE9,       // PTB1
    ADC0_SE10,      // PTA7
    ADC0_SE11,      // PTA8
    ADC0_SE12,      // PTB2
    ADC0_SE13,      // PTB3
    ADC0_SE14,      // PTC0
    ADC0_SE15,      // PTC1
    ADC0_SE16,      // ADC0_SE16
    ADC0_SE17,      // PTE24
    ADC0_SE18,      // PTE25
    ADC0_DM0,       // ADC0_DM0
    ADC0_DM1,       // ADC0_DM1
    RES0,           // 保���
    RES1,           // 保���
    DAC0_OUT,       // DAC0输出 不支��ADC
    RES2,           // 保���
    RES3,           // 保���
    Temp0_Sensor,   // Temperature Sensor,��部温度测���，可��ADC��数
    Bandgap0,       // 温度补偿结���带�����������  不支��ADC
    RES4,           // 保���
    VREFH0,         // �����高电������用ADC��数 ,结�����为 2^n-1
    VREFL0,         // �����低电������用ADC��数 ,结�����为 0
    Module0_Dis,    // 不支����ADC

    // ---------------------------------ADC1-------------------------
    ADC1_DP0,
    ADC1_DP1,
    PGA1_DP,        // 不支����ADC
    ADC1_DP3,
    ADC1_SE4a,      // PTE0
    ADC1_SE5a,      // PTE1
    ADC1_SE6a,      // PTE2
    ADC1_SE7a,      // PTE3

    ADC1_SE4b,  // PTC8     不支��软件ADC ,传��� ADC1_SE4b ��软件ADC��数�����会������ADC1_SE4a 处�������
    ADC1_SE5b,  // PTC9     不支��软件ADC
    ADC1_SE6b,  // PTC10    不支��软件ADC
    ADC1_SE7b,  // PTC11    不支��软件ADC

    ADC1_SE8,       // PTB0
    ADC1_SE9,       // PTB1
    ADC1_SE10,      // PTB4
    ADC1_SE11,      // PTB5
    ADC1_SE12,      // PTB6
    ADC1_SE13,      // PTB7
    ADC1_SE14,      // PTB10
    ADC1_SE15,      // PTB11
    ADC1_SE16,      // ADC1_SE16
    ADC1_SE17,      // PTA17
    VREF_OUTPUT,    // VREF Output
    ADC1_DM0,       // ADC1_DM0
    ADC1_DM1,       // ADC1_DM1
    RES5,           //保���
    RES6,
    DAC1_OUT,
    RES7,           //保���
    RES8,
    Temp1_Sensor,
    Bandgap1,       // 温度补偿结���带�����������  不支��ADC
    RES9,
    VREFH1,         // �����高电������用ADC��数 ,结�����为 2^n-1
    VREFL1,         // �����低电������用ADC��数 ,结�����为 0
    Module1_Dis,    // 不支����ADC

} ADCn_Ch_e;

typedef enum  //ADC模���
{
    ADC0,
    ADC1
} ADCn_e;

//精度位数
typedef enum ADC_nbit
{
    ADC_8bit   = 0x00,
    ADC_10bit  = 0x02,
    ADC_12bit  = 0x01,
    ADC_16bit  = 0x03
} ADC_nbit;


//外部��数��口声���
extern uint16   adc_average (ADCn_Ch_e, ADC_nbit,uint8);
extern void     adc_init    (ADCn_Ch_e);                //ADC���������
extern uint16   adc_once    (ADCn_Ch_e, ADC_nbit);      //�����������模��������AD����
extern void     adc_stop    (ADCn_e);                   //��止ADC转换

#ifdef __cplusplus
	}
#endif

#endif /* __MK60_ADC16_H__ */
