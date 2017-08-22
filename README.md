# PPD42_LIB
arduino PPD42_LIB

아두이노 전용 PPD42 GROVE DUST 센서의 라이브러리 입니다.

```cpp
#include"ppd42.h"

PPD42 dust(8, 3000);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print(dust.read());
  Serial.println("%");
}
```

기본 사용예제는 위와 같습니다.

```cpp
PPD42 dust(디지털핀, 샘플링시간);
```

객체는 위와 같이 디지털핀과 샘플링 시간을 지정하여 사용이 가능합니다.


```cpp
double percent = dust.read();
```

double 형식의 실수형 값을 반환 합니다.

위는 센서 신호의 퍼센트 값을 출력합니다.


## 함께 사용하기 좋은 함수


per단위를 pcs및 ug/m^3 단위로 변환 하기 위한 함수 들입니다.

```cpp
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
  return pcs * mass25 * K
}
```
