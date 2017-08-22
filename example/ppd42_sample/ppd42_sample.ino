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
