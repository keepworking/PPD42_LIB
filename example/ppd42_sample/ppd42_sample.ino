#include"ppd42.h"

PPD42 dust(8, 3000);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print(dust.read());
  Serial.println("%");
}
