#include "HAL.h"

uint8_t presetButtonNumber;
uint8_t presetButtonNumberTmp;


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
	
//digitOut[0] = DIG_0;
//digitOut[1] = DIG_1;
//digitOut[2] = DIG_2;
//digitOut[3] = DIG_3;
//digitOut[4] = DIG_4;
//digitOut[5] = DIG_5;

//while(1);

initButton();
	
	
	
while(1){


//for(int i = 0; i < 11; i++){
//digitOut[0] = myDigit[i];
//pause->delay_ms(1000);
//}

  presetButtonNumber = readButton();
  if(presetButtonNumber != 255 && presetButtonNumber != 3 && presetButtonNumber != 4){
    button[presetButtonNumber] += 1;
    button[presetButtonNumber] %= 10;
//    digitOut[presetButtonNumber] = myDigit[button[presetButtonNumber]];

//1
    if(presetButtonNumber==2){
      digitOut[0] = myDigit[button[presetButtonNumber]];
      heater[1] = button[presetButtonNumber];//Мощность нахрева равна цифре на индикаоре
}
//2
    if(presetButtonNumber==5){
digitOut[1] = myDigit[button[presetButtonNumber]];
heater[2] = button[presetButtonNumber];
}
//-
    if(presetButtonNumber==6)digitOut[2] = myDigit[button[presetButtonNumber]];
//+
    if(presetButtonNumber==7)digitOut[3] = myDigit[button[presetButtonNumber]];
//3
    if(presetButtonNumber==8){
digitOut[5] = myDigit[button[presetButtonNumber]];
heater[3] = button[presetButtonNumber];
}
    
//4
    if(presetButtonNumber==1){
      digitOut[4] = myDigit[button[presetButtonNumber]];
      heater[4] = button[presetButtonNumber];
}

    pause->delay_ms(20);
    presetButtonNumberTmp = readButton();
    pause->delay_ms(20);
    presetButtonNumberTmp = readButton();
    while(presetButtonNumberTmp == presetButtonNumber ){
    pause->delay_ms(20);
    presetButtonNumberTmp = readButton();
    }
  }



}//while
}//main
