#include <cc1110.h>

void main(void)
{
  // Set port 0 bit 0 direction to output
  P0DIR |= 0x01;
  P0_0 = ~P0_0;
}
