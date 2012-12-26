
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
  char nums[] = {0b00111111, 0b00000110, 0b01011011, 0b01001111,
    0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111,
    0b01101111, 0b10000000};
  const char numMax = (sizeof(nums) / sizeof(nums[0]));
  char n = 0;
  DDRD = 0b11111111;

  for (;;) {
    char i;

    for (i = 0; i < 5; i++) {
      _delay_ms(30);
    }

    PORTD = nums[n];

    if (++n >= numMax) n = 0;
  }

  return 0;
}
