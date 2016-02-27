/*
 * bitops.c — bit manipulation playground (CE year 2 vibes)
 */
#include <stdio.h>
#include <stdint.h>

void print_bits(uint32_t x) {
 int i;
 for (i = 31; i >= 0; i--) {
 putchar((x & (1u << i)) ? '1' : '0');
 if (i % 8 == 0 && i) putchar(' ');
 }
 putchar('\n');
}

uint32_t set_bit(uint32_t x, int n) { return x | (1u << n); }
uint32_t clear_bit(uint32_t x, int n) { return x & ~(1u << n); }
uint32_t toggle_bit(uint32_t x, int n){ return x ^ (1u << n); }

int count_bits(uint32_t x) {
 int c = 0;
 while (x) { c += x & 1u; x >>= 1; }
 return c;
}

int main(void) {
 uint32_t x = 0xA5A5A5A5u;
 printf("start: "); print_bits(x);
 x = set_bit(x, 0);
 printf("set0: "); print_bits(x);
 x = clear_bit(x, 31);
 printf("clr31: "); print_bits(x);
 x = toggle_bit(x, 15);
 printf("tog15: "); print_bits(x);
 printf("popcount = %d\n", count_bits(x));
 return 0;
}
