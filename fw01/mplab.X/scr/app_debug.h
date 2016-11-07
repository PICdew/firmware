/**
 * @file app_debug.h
 * @author OpenFeeder Team <https://github.com/orgs/OpenFeeder/people>
 * @version 1.0
 * @date 06/07/2016
 * @revision history 2
 */

#ifndef APP_DEBUG_H
#define APP_DEBUG_H


//#include "app.h"

/**
 * Section: Global Variable Definitions
 */
#define UART1_BUFFER_SIZE  4


void APP_SerialDebugTasks( void );
void printUSBHostDeviceStatus( void );
uint16_t readIntFromUart1( void );


#endif /* APP_DEBUG_H */


/*******************************************************************************
 End of File
 */