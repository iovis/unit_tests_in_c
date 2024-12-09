#include "dumb_example.h"

int8_t average_three_bytes(int8_t a, int8_t b, int8_t c) {
  return (int8_t)(((int16_t)a + (int16_t)b + (int16_t)c) / 3);
}
