#ifndef __TEST_UTILS_H__
#define __TEST_UTILS_H__

#include <stdint.h>
#include <stdio.h>

// Basic unit test utilities for COMP251.
//
// A test is a function that returns 0 on success and 1 on failure.
//
// Use EXPECT macros to set test expectations; for example:
//
// int test_foo() {
//   EXPECT_UINT_EQ(42, foo()); // returns 1 if expectation fails.
//   return 0;
// }
//
// Test cases can be created and added to suites with struct test_case and
// add_test(). run_tests() runs all tests. The ADD_TEST macro is a convenience
// macro to add a function to a test suite associated with the file the test is
// defined within.
//
// Expectation macros are at the end of the file.

#define TEST_NAME_LEN 80

// A test case
struct test_case {
  char name[TEST_NAME_LEN];  // name of test
  char suite[TEST_NAME_LEN]; // suite the test belongs to
  int (*test)();             // test function; return 0 on success, nonzero on
                             // failure.
};

// Add a test case to the the test suite.
//
// Suites should be added as a group; tests are run in the order that they are
// added. The suite field is metadata for convenience.
void add_test(struct test_case test);

// Run all tests.
//
// fail_fast indicates whether the harness should continue running tests after a
// failure.
//
// clean_after indicates whether the harness should clean up after running
// tests.
void run_tests(int fail_fast, int clean_after);

// Clean up after tests.
void cleanup();

// Returns the number of pages allocated to the process.
//
// Can be used by tests that measure memory consumption.
uint64_t total_mem_alloc();

// Macro to add a test. The suite will be the file of the caller.
#define ADD_TEST(fn)                                                           \
  do {                                                                         \
    struct test_case tc;                                                       \
    tc.test = fn;                                                              \
    snprintf(tc.suite, TEST_NAME_LEN, "%s", __FILE__);                         \
    snprintf(tc.name, TEST_NAME_LEN, "%s", "" #fn "");                         \
    add_test(tc);                                                              \
  } while (0);

// Test expectation macros

#define EXPECT_BOOL_INTERNAL(expr, pos, msg, fmt)                              \
  do {                                                                         \
    unsigned long r = (unsigned long)(expr);                                   \
    if ((!pos && r) || (pos && !r)) {                                          \
      fprintf(stderr,                                                          \
              "[%s:%d] Assertion %s failed (expected: " msg "; actual: " fmt   \
              ")\n",                                                           \
              __FILE__, __LINE__, "" #expr "", r);                             \
      return 1;                                                                \
    }                                                                          \
  } while (0);

#define EXPECT_TRUE(expr) EXPECT_BOOL_INTERNAL(expr, 1, "nonzero", "%lu")
#define EXPECT_FALSE(expr) EXPECT_BOOL_INTERNAL(expr, 0, "0", "%lu")

#define EXPECT_OPERATOR(val0, val1, OP, fmt, type)                             \
  do {                                                                         \
    type r0 = (val0);                                                          \
    type r1 = (val1);                                                          \
    if ((r0)OP(r1)) {                                                          \
    } else {                                                                   \
      fprintf(stderr,                                                          \
              "[%s:%d] Assertion %s failed (expected: " fmt "; actual: " fmt   \
              ")\n",                                                           \
              __FILE__, __LINE__, "" #val0 " " #OP " " #val1 "", val0, val1);  \
      return 1;                                                                \
    }                                                                          \
  } while (0);

#define EXPECT_INT_LT(val0, val1) EXPECT_OPERATOR(val0, val1, <, "%d", int)
#define EXPECT_INT_LTE(val0, val1) EXPECT_OPERATOR(val0, val1, <=, "%d", int)
#define EXPECT_INT_GT(val0, val1) EXPECT_OPERATOR(val0, val1, >, "%d", int)
#define EXPECT_INT_GTE(val0, val1) EXPECT_OPERATOR(val0, val1, >=, "%d", int)
#define EXPECT_INT_EQ(val0, val1) EXPECT_OPERATOR(val0, val1, ==, "%d", int)
#define EXPECT_INT_NEQ(val0, val) EXPECT_OPERATOR(val0, val1, !=, "%d", int)

#define EXPECT_UINT_LT(val0, val1)                                             \
  EXPECT_OPERATOR(val0, val1, <, "%u", unsigned int)
#define EXPECT_UINT_LTE(val0, val1)                                            \
  EXPECT_OPERATOR(val0, val1, <=, "%u", unsigned int)
#define EXPECT_UINT_GT(val0, val1)                                             \
  EXPECT_OPERATOR(val0, val1, >, "%u", unsigned int)
#define EXPECT_UINT_GTE(val0, val1)                                            \
  EXPECT_OPERATOR(val0, val1, >=, "%u", unsigned int)
#define EXPECT_UINT_EQ(val0, val1)                                             \
  EXPECT_OPERATOR(val0, val1, ==, "%u", unsigned int)
#define EXPECT_UINT_NEQ(val0, val)                                             \
  EXPECT_OPERATOR(val0, val1, !=, "%u", unsigned int)

#define EXPECT_LONG_LT(val0, val1) EXPECT_OPERATOR(val0, val1, <, "%ld", long)
#define EXPECT_LONG_LTE(val0, val1) EXPECT_OPERATOR(val0, val1, <=, "%ld", long)
#define EXPECT_LONG_GT(val0, val1) EXPECT_OPERATOR(val0, val1, >, "%ld", long)
#define EXPECT_LONG_GTE(val0, val1) EXPECT_OPERATOR(val0, val1, >=, "%ld", long)
#define EXPECT_LONG_EQ(val0, val1) EXPECT_OPERATOR(val0, val1, ==, "%ld", long)
#define EXPECT_LONG_NEQ(val0, val) EXPECT_OPERATOR(val0, val1, !=, "%ld", long)

#define EXPECT_ULONG_LT(val0, val1)                                            \
  EXPECT_OPERATOR(val0, val1, <, "%lu", unsigned long)
#define EXPECT_ULONG_LTE(val0, val1)                                           \
  EXPECT_OPERATOR(val0, val1, <=, "%lu", unsigned long)
#define EXPECT_ULONG_GT(val0, val1)                                            \
  EXPECT_OPERATOR(val0, val1, >, "%lu", unsigned long)
#define EXPECT_ULONG_GTE(val0, val1)                                           \
  EXPECT_OPERATOR(val0, val1, >=, "%lu", unsigned long)
#define EXPECT_ULONG_EQ(val0, val1)                                            \
  EXPECT_OPERATOR(val0, val1, ==, "%lu", unsigned long)
#define EXPECT_ULONG_NEQ(val0, val)                                            \
  EXPECT_OPERATOR(val0, val1, !=, "%lu", unsigned long)

#define EXPECT_PTR_EQ(val0, val1) EXPECT_OPERATOR(val0, val1, ==, "%p", void *)
#define EXPECT_PTR_NEQ(val0, val1) EXPECT_OPERATOR(val0, val1, !=, "%p", void *)

#define EXPECT_NULL(val0) EXPECT_BOOL_INTERNAL(val0, 0, "null", "%lx")
#define EXPECT_NOTNULL(val0) EXPECT_BOOL_INTERNAL(val0, 1, "not null", "%lx")

#endif
