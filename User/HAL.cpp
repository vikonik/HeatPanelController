#include "HAL.h"

DELAY *pause;
SPI *spi;
	PortMapIO *cs;  
  PortMapIO *oe;  
  PortMapIO *mr;  
	PortMapIO *sck;
	PortMapIO *mosi;
	
SPI *button_spi;
PortMapIO *button_CS;
PortMapIO *button_SH;
PortMapIO *button_SCK;
PortMapIO *button_MISO;
	
TIMER *timer;	

uint8_t digitOut[6];//индикаторы на выход
uint8_t flagTimerLed = 0;

void initMCU(void){
uint32_t  timeout = 0xfffff; // Счетчик времени ожидания
 while( timeout-- ) { };
  RCC rcc(80);
  pause = new DELAY;
timer = new TIMER(MDR_TIMER1, 1000);
}

/**/
void initUart(void){
//  PortMapIO rx(MDR_PORTD,
//    PORT_Pin_0,
//    PORT_OE_IN,
//    PORT_PULL_UP_OFF,
//    PORT_PULL_DOWN_OFF,
//    PORT_PD_SHM_OFF,
//    PORT_PD_DRIVER,
//    PORT_GFEN_OFF,
//    PORT_FUNC_ALTER,
//    PORT_SPEED_MAXFAST,
//    PORT_MODE_DIGITAL);

//  PortMapIO tx(MDR_PORTD,
//    PORT_Pin_1,
//    PORT_OE_OUT,
//    PORT_PULL_UP_OFF,
//    PORT_PULL_DOWN_OFF,
//    PORT_PD_SHM_OFF,
//    PORT_PD_DRIVER,
//    PORT_GFEN_OFF,
//    PORT_FUNC_ALTER,
//    PORT_SPEED_MAXFAST,
//    PORT_MODE_DIGITAL);

//   uart = new UART(MDR_UART2, 115200, UART_WordLength8b, UART_StopBits1, UART_Parity_No,UART_FIFO_OFF, UART_HardwareFlowControl_RXE | UART_HardwareFlowControl_TXE);
//uart->enableIRQ();
}

/*
Управляем индикторами через SPI

*/
void initLed(void){

 cs = new PortMapIO(SPI_PORT, pinLED_CS);  
 oe = new PortMapIO(SPI_PORT, pinLED_OE);  
 mr = new PortMapIO(SPI_PORT, pinLED_MR);  


   sck = new PortMapIO(SPI_PORT,
    pinLED_SCK,
    PORT_OE_OUT,
    PORT_PULL_UP_OFF,
    PORT_PULL_DOWN_OFF,
    PORT_PD_SHM_OFF,
    PORT_PD_DRIVER,
    PORT_GFEN_OFF,
    PORT_FUNC_ALTER,
    PORT_SPEED_MAXFAST,
    PORT_MODE_DIGITAL);

   mosi = new PortMapIO(SPI_PORT,
    pinLED_MOSI,
    PORT_OE_OUT,
    PORT_PULL_UP_OFF,
    PORT_PULL_DOWN_OFF,
    PORT_PD_SHM_OFF,
    PORT_PD_DRIVER,
    PORT_GFEN_OFF,
    PORT_FUNC_ALTER,
    PORT_SPEED_MAXFAST,
    PORT_MODE_DIGITAL);

		mr->setHigh();
		oe->setLow();
		spi = new SPI(MDR_SSP2, SSP_WordLength16b); 


}
/**/
void writeLed(uint8_t ledNumber, uint8_t *digit[]){
uint16_t tmp = 	(1 << ledNumber);
tmp <<= 8;
tmp |= *digit[ledNumber];	
	
spi->transmit(&tmp);
	cs->setHigh();
	cs->setLow();
}

/**/
void writeLed(uint8_t ledNumber){
	
uint16_t tmp = digitOut[ledNumber];//	(1 << ledNumber);
tmp <<= 8;
tmp |= (1 << ledNumber);	
//uint16_t tmp = 0xAAAA;	
spi->transmit(&tmp);//Просунули данные в регистры
	//Дрыгнули ногой для записи
	cs->setHigh();
	cs->setLow();
}


/*
Инициализация кнопок
*/
void initButton(){
 button_CS = new PortMapIO(SPI_BUTTON_PORT, pinBUTTON_CS);  
 button_SH = new PortMapIO(SPI_BUTTON_PORT, pinBUTTON_SH);  

   button_SCK = new PortMapIO(SPI_BUTTON_PORT,
    pinBUTTON_SCK,
    PORT_OE_OUT,
    PORT_PULL_UP_OFF,
    PORT_PULL_DOWN_OFF,
    PORT_PD_SHM_OFF,
    PORT_PD_DRIVER,
    PORT_GFEN_OFF,
    PORT_FUNC_ALTER,
    PORT_SPEED_MAXFAST,
    PORT_MODE_DIGITAL);

   button_MISO = new PortMapIO(SPI_BUTTON_PORT,
    pinBUTTON_MISO,
    PORT_OE_IN,
    PORT_PULL_UP_ON,
    PORT_PULL_DOWN_OFF,
    PORT_PD_SHM_OFF,
    PORT_PD_DRIVER,
    PORT_GFEN_OFF,
    PORT_FUNC_ALTER,
    PORT_SPEED_MAXFAST,
    PORT_MODE_DIGITAL);


		button_spi = new SPI(MDR_SSP1, SSP_WordLength8b); 
		button_CS->setLow();
	 button_SH->setHigh();
	 
button_SCK->setPinAsOutput();	
	button_MISO->setPinAsInput();
	 button_SH->setHigh();	 
	 button_SCK->setHigh();
}
/*
Читаем кнопки
uint8_t *digit[] - индикатлор для каждой кнопки
*/
void readButton(uint8_t *digit){

	button_SCK->setHigh();
	
	button_SH->setLow();
//	button_SCK->setHigh();
//	button_SCK->setLow();

	  button_SH->setHigh();	
	
//	button_SCK->setHigh();
//	button_SCK->setLow();	

	uint16_t tmp = 0;
for(int i = 0; i<8; i++){
		button_SCK->setHigh();
		button_SCK->setLow();
	if(button_MISO->PortMapIoPORT_Read() & 0x08)
tmp |=(1 << (7-i));
} 
	
//	button_SCK->setPinAsAlternative(1,1);	
	
//	  uint16_t tmp = 0xFFFF;
//	tmp = button_MISO->PortMapIoPORT_Read();
//		tmp =	button_spi->transmit(&tmp);
 		tmp = tmp;
}

