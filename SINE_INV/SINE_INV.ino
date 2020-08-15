#include <TimerOne.h>
#include "sineTable.h"

int counter;

void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  Timer1.initialize(100);  // 100uS
  Timer1.pwm(9, 100);
  Timer1.pwm(10, 100);
  Timer1.attachInterrupt(sineWave);
}

void loop() {

}

void sineWave() {
  counter++;
  if(counter == 200) counter = 0;
  if (counter < 100) {
    Timer1.setPwmDuty(9, sineVal[0][counter]);
    Timer1.setPwmDuty(10, 0);
  }
  else {
    Timer1.setPwmDuty(9, 0);
    Timer1.setPwmDuty(10, sineVal[0][counter - 100]);
  }
}
