#include "HAL.h"

uint8_t qwe;

int main(void){
initMCU();
initUart();
initLed();
//	
////cs->setHigh();
////	cs->setLow();
////cs->setHigh();
////	cs->setLow();
////cs->setHigh();
////	cs->setLow();
//	
//digitOut[0] = 0xAA;
//digitOut[1] = 0xAA;
//digitOut[2] = 0xAA;
//digitOut[3] = 0xAA;
//digitOut[4] = 0xAA;
//digitOut[5] = 0xAA;

//for(int i = 0; i < 6; i++){
//	writeLed(i);
//pause->delay_ms(250);
//	
//}

initButton();
	
	
	
while(1){
readButton(&qwe);


}//while
}//main
