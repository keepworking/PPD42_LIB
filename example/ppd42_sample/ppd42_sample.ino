#include"ppd42.h"

PPD42 dust(8, 3000);

void setup() {
  Serial.begin(9600);
}


double per = 0;
double conc = 0;
double ugm3 = 0;

void loop() {
  per = dust.read();
  conc = per2pcs(per);
  ugm3 = pcs2ugm3(conc);
  Serial.print(ugm3);
  Serial.println("ug/m^3");
}

double per2pcs(double per){
  return 1.1*pow(per,3) - 3.8*pow(per,2) + 520*per +0.62;
}

//pcs 단위를 ug/m^3 단위로 변환하는 함수 입니다.
double pcs2ugm3(double pcs){
  double den,r25,vol25,mass25;
  den=1.65*pow(10,12);
  r25=0.44*pow(10,-6);
  vol25=(4/3)*PI*pow(r25,3);
  mass25=den*vol25;
  double K = 3531.5;
  return pcs * mass25 * K;
}
