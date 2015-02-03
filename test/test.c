#include <cc1110.h>


void delay(int msec) {
  int i,j;
  
  for (i=0; i<msec; i++)
    for (j=0; j<1000; j++);
}

void main(void) {
  //P0DIR |= (1<<3);
  //P1SEL&=~0x01;
  P0DIR |= 0x01;
  P0_0 = 0;
  
  while (1) {
    P0_0 ^= 1;
    delay(1000);
  }
}

