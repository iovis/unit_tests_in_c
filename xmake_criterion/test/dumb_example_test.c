#include "dumb_example.h"

#include <criterion/criterion.h>
#include <criterion/new/assert.h>

Test(dumb_example, average_three_bytes_example) {
  cr_assert(eq(int, average_three_bytes(1, 2, 3), 2));
}

Test(dumb_example, average_three_bytes_should_average_mid_range_values) {
  cr_expect(eq(int, average_three_bytes(30, 40, 50), 40));
  cr_expect(eq(int, average_three_bytes(10, 70, 40), 40));
  cr_expect(eq(int, average_three_bytes(33, 33, 33), 33));
}

Test(dumb_example, average_three_bytes_should_average_high_values) {
  cr_expect(eq(int, average_three_bytes(70, 80, 90), 80));
  cr_expect(eq(int, average_three_bytes(127, 127, 127), 127));
  cr_expect(eq(int, average_three_bytes(0, 126, 126), 84));
}
