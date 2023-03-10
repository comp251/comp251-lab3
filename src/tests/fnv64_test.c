#include "../fnv64.h"

#include "test_utils.h"

int test_empty() {
  EXPECT_ULONG_EQ(0xcbf29ce484222325, fnv64(""));
  EXPECT_ULONG_EQ(0xaf63bd4c8601b7ff, fnv64(" "));
  return 0;
}

int test_aircodes() {
  EXPECT_ULONG_EQ(0xd832be186b1f1909, fnv64("SFO"));
  EXPECT_ULONG_EQ(0xd86fe0186b530166, fnv64("ATL"));
  return 0;
}

int test_long() {
  EXPECT_ULONG_EQ(
      0x097de0b5a98040b9,
      fnv64("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmn"
            "opqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzab"
            "cdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnop"
            "qrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd"
            "efghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqr"
            "stuvwxyzabcdefghijklmnopqrstuvwxyz"));
  return 0;
}

int main() {
  ADD_TEST(test_empty);
  ADD_TEST(test_aircodes);
  ADD_TEST(test_long);

  run_tests(/*fail_fast=*/1, /*clean_after=*/1);
  return 0;
}
