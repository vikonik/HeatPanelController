#include "HAL.h"

uint8_t qwe;

int main(void){
initMCU();
initUart();
initLed();
	
//cs->setHigh();
//	cs->setLow();
//cs->setHigh();
//	cs->setLow();
//cs->setHigh();
//	cs->setLow();
	
digitOut[0] = DIG_0;
digitOut[1] = DIG_1;
digitOut[2] = DIG_2;
digitOut[3] = DIG_3;
digitOut[4] = DIG_4;
digitOut[5] = DIG_5;



initButton();
	
	
	
while(1){


for(int i = 0; i < 11; i++){
digitOut[0] = myDigit[i];
pause->delay_ms(1000);
}


//readButton(&qwe);
}//while
}//main
