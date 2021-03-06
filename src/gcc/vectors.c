/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Vectors.c
**     Project     : ProcessorExpert
**     Processor   : MK60DN512ZVLQ10
**     Version     : Component 01.000, Driver 01.04, CPU db: 3.00.001
**     Compiler    : GNU C Compiler
**     Date/Time   : 2014-01-15, 23:29, # CodeGen: 0
**     Abstract    :
**
**     Settings    :
**
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file Vectors.c
** @version 01.04
** @date 2014-01-15, 23:29, # CodeGen: 0
** @brief
**
*/
/*!
**  @addtogroup Vectors_module Vectors module documentation
**  @{
*/

#include "vectors.h"
#include "hw_common.h"

HardFaultHandler __g_hard_fault_handler = NULL;


/* ISR prototype */
extern uint32_t __SP_INIT;
extern void __thumb_startup( void );


/*lint -esym(765,__vect_table) Disable MISRA rule (8.10) checking for symbols (__vect_table). Definition of the interrupt vector table placed by linker on a predefined location. */
/*lint -save  -e926 -e927 -e928 -e929 Disable MISRA rule (11.4) checking. Need to explicitly cast pointers to the general ISR for Interrupt vector table */

__attribute__ ((section (".vectortable"))) const tVectorTable __vect_table = { /* Interrupt vector table */

	/* ISR name                            No. Address      Pri Name                           Description */
	&__SP_INIT,                       /* 0x00  0x00000000   -   ivINT_Initial_Stack_Pointer    used by PE */
	{
	(tIsrFunc)&__thumb_startup,       /* 0x01  0x00000004   -   ivINT_Initial_Program_Counter  used by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x02  0x00000008   -2   ivINT_NMI                      used by PE */
	(tIsrFunc)&HardFaultHandlerAsm,   /* 0x03  0x0000000C   -1   ivINT_Hard_Fault               unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x04  0x00000010   -   ivINT_Mem_Manage_Fault         unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x05  0x00000014   -   ivINT_Bus_Fault                unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x06  0x00000018   -   ivINT_Usage_Fault              unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x07  0x0000001C   -   ivINT_Reserved7                unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x08  0x00000020   -   ivINT_Reserved8                unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x09  0x00000024   -   ivINT_Reserved9                unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x0A  0x00000028   -   ivINT_Reserved10               unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x0B  0x0000002C   -   ivINT_SVCall                   unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x0C  0x00000030   -   ivINT_DebugMonitor             unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x0D  0x00000034   -   ivINT_Reserved13               unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x0E  0x00000038   -   ivINT_PendableSrvReq           unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x0F  0x0000003C   -   ivINT_SysTick                  unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x10  0x00000040   -   ivINT_DMA0                     unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x11  0x00000044   -   ivINT_DMA1                     unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x12  0x00000048   -   ivINT_DMA2                     unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x13  0x0000004C   -   ivINT_DMA3                     unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x14  0x00000050   -   ivINT_DMA4                     unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x15  0x00000054   -   ivINT_DMA5                     unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x16  0x00000058   -   ivINT_DMA6                     unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x17  0x0000005C   -   ivINT_DMA7                     unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x18  0x00000060   -   ivINT_DMA8                     unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x19  0x00000064   -   ivINT_DMA9                     unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x1A  0x00000068   -   ivINT_DMA10                    unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x1B  0x0000006C   -   ivINT_DMA11                    unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x1C  0x00000070   -   ivINT_DMA12                    unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x1D  0x00000074   -   ivINT_DMA13                    unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x1E  0x00000078   -   ivINT_DMA14                    unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x1F  0x0000007C   -   ivINT_DMA15                    unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x20  0x00000080   -   ivINT_DMA_Error                unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x21  0x00000084   -   ivINT_MCM                      unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x22  0x00000088   -   ivINT_FTFL                     unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x23  0x0000008C   -   ivINT_Read_Collision           unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x24  0x00000090   -   ivINT_LVD_LVW                  unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x25  0x00000094   -   ivINT_LLW                      unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x26  0x00000098   -   ivINT_Watchdog                 unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x27  0x0000009C   -   ivINT_RNG                      unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x28  0x000000A0   -   ivINT_I2C0                     unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x29  0x000000A4   -   ivINT_I2C1                     unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x2A  0x000000A8   -   ivINT_SPI0                     unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x2B  0x000000AC   -   ivINT_SPI1                     unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x2C  0x000000B0   -   ivINT_SPI2                     unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x2D  0x000000B4   -   ivINT_CAN0_ORed_Message_buffer unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x2E  0x000000B8   -   ivINT_CAN0_Bus_Off             unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x2F  0x000000BC   -   ivINT_CAN0_Error               unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x30  0x000000C0   -   ivINT_CAN0_Tx_Warning          unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x31  0x000000C4   -   ivINT_CAN0_Rx_Warning          unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x32  0x000000C8   -   ivINT_CAN0_Wake_Up             unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x33  0x000000CC   -   ivINT_Reserved51               unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x34  0x000000D0   -   ivINT_Reserved52               unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x35  0x000000D4   -   ivINT_CAN1_ORed_Message_buffer unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x36  0x000000D8   -   ivINT_CAN1_Bus_Off             unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x37  0x000000DC   -   ivINT_CAN1_Error               unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x38  0x000000E0   -   ivINT_CAN1_Tx_Warning          unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x39  0x000000E4   -   ivINT_CAN1_Rx_Warning          unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x3A  0x000000E8   -   ivINT_CAN1_Wake_Up             unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x3B  0x000000EC   -   ivINT_Reserved59               unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x3C  0x000000F0   -   ivINT_Reserved60               unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x3D  0x000000F4   -   ivINT_UART0_RX_TX              unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x3E  0x000000F8   -   ivINT_UART0_ERR                unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x3F  0x000000FC   -   ivINT_UART1_RX_TX              unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x40  0x00000100   -   ivINT_UART1_ERR                unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x41  0x00000104   -   ivINT_UART2_RX_TX              unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x42  0x00000108   -   ivINT_UART2_ERR                unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x43  0x0000010C   -   ivINT_UART3_RX_TX              unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x44  0x00000110   -   ivINT_UART3_ERR                unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x45  0x00000114   -   ivINT_UART4_RX_TX              unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x46  0x00000118   -   ivINT_UART4_ERR                unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x47  0x0000011C   -   ivINT_UART5_RX_TX              unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x48  0x00000120   -   ivINT_UART5_ERR                unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x49  0x00000124   -   ivINT_ADC0                     unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x4A  0x00000128   -   ivINT_ADC1                     unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x4B  0x0000012C   -   ivINT_CMP0                     unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x4C  0x00000130   -   ivINT_CMP1                     unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x4D  0x00000134   -   ivINT_CMP2                     unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x4E  0x00000138   -   ivINT_FTM0                     unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x4F  0x0000013C   -   ivINT_FTM1                     unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x50  0x00000140   -   ivINT_FTM2                     unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x51  0x00000144   -   ivINT_CMT                      unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x52  0x00000148   -   ivINT_RTC                      unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x53  0x0000014C   -   ivINT_Reserved83               unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x54  0x00000150   -   ivINT_PIT0                     unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x55  0x00000154   -   ivINT_PIT1                     unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x56  0x00000158   -   ivINT_PIT2                     unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x57  0x0000015C   -   ivINT_PIT3                     unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x58  0x00000160   -   ivINT_PDB0                     unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x59  0x00000164   -   ivINT_USB0                     unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x5A  0x00000168   -   ivINT_USBDCD                   unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x5B  0x0000016C   -   ivINT_ENET_1588_Timer          unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x5C  0x00000170   -   ivINT_ENET_Transmit            unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x5D  0x00000174   -   ivINT_ENET_Receive             unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x5E  0x00000178   -   ivINT_ENET_Error               unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x5F  0x0000017C   -   ivINT_I2S0                     unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x60  0x00000180   -   ivINT_SDHC                     unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x61  0x00000184   -   ivINT_DAC0                     unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x62  0x00000188   -   ivINT_DAC1                     unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x63  0x0000018C   -   ivINT_TSI0                     unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x64  0x00000190   -   ivINT_MCG                      unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x65  0x00000194   -   ivINT_LPTimer                  unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x66  0x00000198   -   ivINT_Reserved102              unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x67  0x0000019C   -   ivINT_PORTA                    unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x68  0x000001A0   -   ivINT_PORTB                    unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x69  0x000001A4   -   ivINT_PORTC                    unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x6A  0x000001A8   -   ivINT_PORTD                    unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x6B  0x000001AC   -   ivINT_PORTE                    unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x6C  0x000001B0   -   ivINT_Reserved108              unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x6D  0x000001B4   -   ivINT_Reserved109              unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x6E  0x000001B8   -   ivINT_Reserved110              unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x6F  0x000001BC   -   ivINT_Reserved111              unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x70  0x000001C0   -   ivINT_Reserved112              unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x71  0x000001C4   -   ivINT_Reserved113              unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x72  0x000001C8   -   ivINT_Reserved114              unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x73  0x000001CC   -   ivINT_Reserved115              unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x74  0x000001D0   -   ivINT_Reserved116              unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x75  0x000001D4   -   ivINT_Reserved117              unused by PE */
	(tIsrFunc)&DefaultIsr,            /* 0x76  0x000001D8   -   ivINT_Reserved118              unused by PE */
	(tIsrFunc)&DefaultIsr             /* 0x77  0x000001DC   -   ivINT_Reserved119              unused by PE */
	}
};
/*lint -restore Enable MISRA rule (11.4) checking. */

__attribute__ ((section (".vectortableram"))) tVectorTable __vect_ram; /* Interrupt vector table in RAM */


void InitVectorTable(void)
{
	const Byte *rom = (const Byte*)&__vect_table;
	Byte *ram = (Byte*)&__vect_ram;

    for (uint32_t i = 0; i < sizeof(tVectorTable); ++i)
    {
    	*ram++ = *rom++;
    }

	assert((uint32_t)(&__vect_ram) % 0x200 == 0);   //Vector Table base offset field. This value must be a multiple of 0x200.
	/* Write the VTOR with the new value */
	SCB_VTOR = (uint32_t)(&__vect_ram);
}

void SetIsr(VECTORn_t vector, tIsrFunc handler)
{
	__vect_ram.__fun[vector - 1] = handler ? handler : DefaultIsr;
}

void EnableIsr(VECTORn_t vector)
{
	NVIC_EnableIRQ(vector - (DMA0_VECTORn - DMA0_IRQn));
}

void DisableIsr(VECTORn_t vector)
{
	NVIC_DisableIRQ(vector - (DMA0_VECTORn - DMA0_IRQn));
}

void DefaultIsr(void)
{
	LOG_W("Unhandled interrupt (VECTORn_t == %d)\n",
			*(volatile uint8_t*)(0xE000ED04));
}

/**
 * HardFaultHandler:
 * Alternative Hard Fault handler to help debug the reason for a fault.
 * To use, edit the vector table to reference this function in the HardFault vector
 * This code is suitable for Cortex-M3 and Cortex-M0 cores
 */
void HardFaultHandlerAsm(void)
{
	/*
	* Get the appropriate stack pointer, depending on our mode,
	* and use it as the parameter to the C handler
	*/
	__asm("MOVS   R0, #4  \n"
			"MOV    R1, LR  \n"
			"TST    R0, R1  \n"
			"BEQ    _MSP    \n"
			"MRS    R0, PSP \n"
			"B      HardFaultHandlerC      \n"
			"_MSP:  \n"
			"MRS    R0, MSP \n"
			"B      HardFaultHandlerC      \n") ;
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"

/**
 * HardFaultHandlerC:
 * This is called from the HardFault_HandlerAsm with a pointer the Fault stack
 * as the parameter. We can then read the values from the stack and place them
 * into local variables for ease of reading.
 * We then read the various Fault Status and Address Registers to help decode
 * cause of the fault.
 * The function ends with a BKPT instruction to force control back into the debugger
 */
void HardFaultHandlerC(unsigned long *hardfault_args)
{
	volatile unsigned long stacked_r0;
	volatile unsigned long stacked_r1;
	volatile unsigned long stacked_r2;
	volatile unsigned long stacked_r3;
	volatile unsigned long stacked_r12;
	volatile unsigned long stacked_lr;
	volatile unsigned long stacked_pc;
	volatile unsigned long stacked_psr;
	volatile unsigned long _CFSR;
	volatile unsigned long _HFSR;
	volatile unsigned long _DFSR;
	volatile unsigned long _AFSR;
	volatile unsigned long _BFAR;
	volatile unsigned long _MMAR;

	stacked_r0 = ((unsigned long)hardfault_args[0]);
	stacked_r1 = ((unsigned long)hardfault_args[1]);
	stacked_r2 = ((unsigned long)hardfault_args[2]);
	stacked_r3 = ((unsigned long)hardfault_args[3]);
	stacked_r12 = ((unsigned long)hardfault_args[4]);
	stacked_lr = ((unsigned long)hardfault_args[5]);
	stacked_pc = ((unsigned long)hardfault_args[6]);
	stacked_psr = ((unsigned long)hardfault_args[7]);

	// Configurable Fault Status Register
	// Consists of MMSR, BFSR and UFSR
	_CFSR = (*((volatile unsigned long*)(0xE000ED28)));

	// Hard Fault Status Register
	_HFSR = (*((volatile unsigned long*)(0xE000ED2C)));

	// Debug Fault Status Register
	_DFSR = (*((volatile unsigned long*)(0xE000ED30)));

	// Auxiliary Fault Status Register
	_AFSR = (*((volatile unsigned long*)(0xE000ED3C)));

	// Read the Fault Address Registers. These may not contain valid values.
	// Check BFARVALID/MMARVALID to see if they are valid values
	// MemManage Fault Address Register
	_MMAR = (*((volatile unsigned long*)(0xE000ED34)));
	// Bus Fault Address Register
	_BFAR = (*((volatile unsigned long*)(0xE000ED38)));

	if (__g_hard_fault_handler)
	{
		__g_hard_fault_handler();
	}
	__BREAKPOINT(); // Break into the debugger
}

#pragma GCC diagnostic pop

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.2 [05.06]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
