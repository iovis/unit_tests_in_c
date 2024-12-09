#include "munit.h"

#include "dumb_example.h"

static MunitResult
test_average_three_bytes_example(const MunitParameter params[], void *data) {
  munit_assert_int8(average_three_bytes(1, 2, 3), ==, 2);

  return MUNIT_OK;
}

static MunitResult test_average_three_bytes_should_average_mid_range_values(
    const MunitParameter params[], void *data) {
  munit_assert_int8(average_three_bytes(30, 40, 50), ==, 40);
  munit_assert_int8(average_three_bytes(10, 70, 40), ==, 40);
  munit_assert_int8(average_three_bytes(33, 33, 33), ==, 33);

  return MUNIT_OK;
}

static MunitResult test_average_three_bytes_should_average_high_values(
    const MunitParameter params[], void *data) {
  munit_assert_int8(average_three_bytes(70, 80, 90), ==, 80);
  munit_assert_int8(average_three_bytes(127, 127, 127), ==, 127);
  munit_assert_int8(average_three_bytes(0, 126, 126), ==, 84);

  return MUNIT_OK;
}

// clang-format off
// MunitTest
// - test name
// - test function
// - setup function (optional)
// - teardown function (optional)
// - test options
// - NULL (terminate array)
//
// You have to end the array of tests with an null test
MunitTest test_suite_tests[] = {
  {"/average_three_bytes/example", test_average_three_bytes_example, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
  {"/average_three_bytes/mid_range_values", test_average_three_bytes_should_average_mid_range_values, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
  {"/average_three_bytes/high_values", test_average_three_bytes_should_average_high_values, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
  {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

// MunitSuite
// - suite name
// - tests array
// - sub suites
// - number of iterations for each test
// - suite options
const MunitSuite test_suite = {
  "munit_examples",
  test_suite_tests,
  NULL,
  1,
  MUNIT_SUITE_OPTION_NONE
};
// clang-format on

int main(int argc, char *argv[]) {
  return munit_suite_main(&test_suite, NULL, argc, argv);
}
