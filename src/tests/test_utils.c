#include "test_utils.h"

#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

uint64_t total_mem_alloc() {
  static char buff[PATH_MAX];
  pid_t pid = getpid();
  sprintf(buff, "/proc/%d/statm", pid);
  FILE *f = fopen(buff, "r");
  uint64_t usage;
  fscanf(f, "%lu ", &usage);
  fclose(f);
  return usage;
}

struct test_case *tests = NULL;
int n_tests = 0;

void add_test(struct test_case test) {
  n_tests++;
  tests = realloc(tests, n_tests * sizeof(struct test_case));
  tests[n_tests - 1] = test;
}

void cleanup() {
  free(tests);
  tests = NULL;
  n_tests = 0;
}

void run_tests(int fail_fast, int clean_after) {
  int maxl = 0;
  for (int i = 0; i < n_tests; i++) {
    int len = strnlen(tests[i].name, TEST_NAME_LEN);
    maxl = len > maxl ? len : maxl;
  }
  int failures = 0;
  for (int i = 0; i < n_tests; i++) {
    if (i == 0 || strcmp(tests[i].suite, tests[i - 1].suite) != 0) {
      printf("--- %s ---\n", tests[i].suite);
    }
    int len = strnlen(tests[i].name, TEST_NAME_LEN);
    printf("Running %s ...", tests[i].name);
    // flush stdout so that test name is shown before a crash/failure.
    fflush(stdout);
    for (int i = 0; i < maxl - len; i++) {
      printf(".");
    }
    if (tests[i].test()) {
      printf("(failed) ❌\n");
      failures++;
      if (fail_fast) {
        break;
      }
      continue;
    }
    printf("(passed) ✅\n");
  }
  printf("%s (%d / %d succeeded)\n", failures > 0 ? "FAILED 😔" : "PASSED 🎉",
         n_tests - failures, n_tests);
  if (clean_after) {
    cleanup();
  }
}
