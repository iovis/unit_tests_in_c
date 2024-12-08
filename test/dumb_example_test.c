#include "unity.h"

#include "dumb_example.h"

// Apparently required
void setUp(void) {}
void tearDown(void) {}

void test_average_three_bytes_example(void) {
  TEST_ASSERT_EQUAL(average_three_bytes(1, 2, 3), 2);
}

void test_average_three_bytes_should_average_mid_range_values(void) {
  TEST_ASSERT_EQUAL(average_three_bytes(30, 40, 50), 40);
  TEST_ASSERT_EQUAL(average_three_bytes(10, 70, 40), 40);
  TEST_ASSERT_EQUAL(average_three_bytes(33, 33, 33), 33);
}

void test_average_three_bytes_should_average_high_values(void) {
  TEST_ASSERT_EQUAL(average_three_bytes(70, 80, 90), 80);
  TEST_ASSERT_EQUAL(average_three_bytes(127, 127, 127), 127);
  TEST_ASSERT_EQUAL(average_three_bytes(0, 126, 126), 84);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_average_three_bytes_example);
  RUN_TEST(test_average_three_bytes_should_average_mid_range_values);
  RUN_TEST(test_average_three_bytes_should_average_high_values);
  return UNITY_END();
}
