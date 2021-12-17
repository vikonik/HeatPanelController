#ifndef _HAL_H
#define _HAL_H
#include "MDR32Fx.h"                    // Device header
#include "MDR32F9Qx_uart.h"             // Keil::Drivers:UART
#include "MDR32F9Qx_timer.h"            // Keil::Drivers:TIMER
#include "MDR32F9Qx_ssp.h"              // Keil::Drivers:SSP
#include "MDR32F9Qx_rst_clk.h"          // Keil::Drivers:RST_CLK
#include "MDR32F9Qx_port.h"             // Keil::Drivers:PORT

#include "MDR32F9Qx_config.h"           // Keil::Device:Startup

#include "portDefenition.h"
#include "port.h" 
#include "RCC.h" 
#include "delay.h" 
#include "uart.h" 
#include "spi.h" 
//#include "FIFO.h" 
#include "timer.h" 
#include "ledind.h"

extern PortMapIO *heat[6];
extern UART *uart;
//extern uint8_t rcvData;
extern DELAY *pause;
extern uint8_t digitOut[6];

extern 	PortMapIO *cs; 
	
extern TIMER *timer;
extern uint8_t button[];
extern uint8_t heater[];

void initMCU(void);
void initRelay(void);
void initUart(void);
void initLed(void);
void writeLed(uint8_t ledNumber, uint8_t *digit[]);
void writeLed(uint8_t ledNumber);
void initButton();
uint8_t readButton(void);


#endif
