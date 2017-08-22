#include "PPD42.h"
PPD42::PPD42(int pin,unsigned long sample){
  Pin = pin;
  Sample = sample;
}

double PPD42::read(){
  Start = millis();
  Count = 0;
  while(millis()-Start < Sample){
    Count+=pulseIn(Pin,LOW);
  }
  return Count/(Sample*10.0);
}

