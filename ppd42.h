#ifndef PPD42_H
#define PPD42_H
#include "Arduino.h"
class PPD42{
  public:
  PPD42(int,unsigned long = 30000);//생성자
  double read();//메소드 함수
  private:
  int Pin;
  unsigned long Sample;
  unsigned long Start;
  unsigned long Count;
};
#endif
