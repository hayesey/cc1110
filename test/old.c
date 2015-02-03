#include <cc1110.h>

#define nop()	__asm nop __endasm;

void delay (unsigned char n) {
  unsigned char i = 0;
  unsigned char j = 0;
  
  n <<= 1;
  while (--n != 0)
    while (--i != 0)
      while (--j != 0)
	nop();
}

void main(void) {
  //P0DIR |= (1<<3);
  P0DIR |= 0x01;
  P0_0 = 0;
  
  while (1)  {
    //P0_0 ^= 1;
    P0_0 = ~P0_0;
    delay(3000);
  }
}

