/**
  System Interrupts Generated Driver File 

  @Company:
    Microchip Technology Inc.

  @File Name:
    interrupt_manager.h

  @Summary:
    This is the generated driver implementation file for setting up the
    interrupts using MPLAB(c) Code Configurator

  @Description:
    This source file provides implementations for MPLAB(c) Code Configurator interrupts.
    Generation Information : 
        Product Revision  :  MPLAB(c) Code Configurator - pic24-dspic-pic32mm : v1.35
        Device            :  PIC24FJ256GB406
    The generated drivers are tested against the following:
        Compiler          :  XC16 1.31
        MPLAB             :  MPLAB X 3.60
*/
/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
    Section: Includes
*/
#include <xc.h>

/**
    void INTERRUPT_Initialize (void)
*/
void INTERRUPT_Initialize (void)
{
    //    RTCI: RTCC - Real-Time Clock and Calendar
    //    Priority: 5
        IPC15bits.RTCIP = 5;
    //    UERI: U2E - UART2 Error
    //    Priority: 2
        IPC16bits.U2ERIP = 2;
    //    UTXI: U2TX - UART2 Transmitter
    //    Priority: 2
        IPC7bits.U2TXIP = 2;
    //    URXI: U2RX - UART2 Receiver
    //    Priority: 2
        IPC7bits.U2RXIP = 2;
    //    UERI: U1E - UART1 Error
    //    Priority: 2
        IPC16bits.U1ERIP = 2;
    //    UTXI: U1TX - UART1 Transmitter
    //    Priority: 2
        IPC3bits.U1TXIP = 2;
    //    URXI: U1RX - UART1 Receiver
    //    Priority: 2
        IPC2bits.U1RXIP = 2;
    //    INT0I: INT0 - External Interrupt 0
    //    Priority: 6
        IPC0bits.INT0IP = 6;
    //    INT3I: INT3 - External Interrupt 3
    //    Priority: 7
        IPC13bits.INT3IP = 7;
    //    INT4I: INT4 - External Interrupt 4
    //    Priority: 7
        IPC13bits.INT4IP = 7;
    //    INT1I: INT1 - External Interrupt 1
    //    Priority: 5
        IPC5bits.INT1IP = 5;
    //    INT2I: INT2 - External Interrupt 2
    //    Priority: 6
        IPC7bits.INT2IP = 6;
    //    MICI: MI2C1 - I2C1 Master Events
    //    Priority: 2
        IPC4bits.MI2C1IP = 2;
    //    SICI: SI2C1 - I2C1 Slave Events
    //    Priority: 2
        IPC4bits.SI2C1IP = 2;
    //    TI: T4 - Timer4
    //    Priority: 2
        IPC6bits.T4IP = 2;
    //    TI: T3 - Timer3
    //    Priority: 4
        IPC2bits.T3IP = 4;
    //    TI: T2 - Timer2
    //    Priority: 4
        IPC1bits.T2IP = 4;

}
