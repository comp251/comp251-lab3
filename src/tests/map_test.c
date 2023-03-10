#include <stdlib.h>
#include <string.h>

#include "../map.h"

#include "airport_codes.h"
#include "test_utils.h"

// Collection of unit tests for map implementation.
//
// All tests call map_free; this test should not leak memory if map_free is
// implemented.

int test_create_basic() {
  // create a map; validate that the map is not null.
  map_t *map = map_create(32);
  EXPECT_NOTNULL(map);
  map_free(&map);
  return 0;
}

int test_create_size() {
  // create a few differently-sized maps; validate that they are different
  // sizes;
  map_t *map = map_create(2);
  EXPECT_NOTNULL(map);
  EXPECT_UINT_EQ(map_size(map), 2);
  map_free(&map);

  map = map_create(1024);
  EXPECT_NOTNULL(map);
  EXPECT_UINT_EQ(map_size(map), 1024);
  map_free(&map);
  return 0;
}

int test_put_once() {
  // Put a single entry in a map. Perform no validation.
  map_t *map = map_create(16);
  EXPECT_NOTNULL(map);
  EXPECT_TRUE(map_put(map, codes[0], cities[0])); // key should be new
  map_free(&map);
  return 0;
}

int test_put_get_once() {
  // Put and retrieve a single entry in a map. Perform validation.
  map_t *map = map_create(16);
  EXPECT_NOTNULL(map);
  map_put(map, codes[0], cities[0]);
  char *val = NULL;
  EXPECT_TRUE(map_get(map, codes[0], (void **)&val)); // key should be present
  EXPECT_TRUE(strcmp(cities[0], val) == 0);           // value should match
  map_free(&map);
  return 0;
}

int test_get_only_check() {
  // Put and retrieve a single entry in a map. Only validate presence.
  map_t *map = map_create(16);
  EXPECT_NOTNULL(map);
  map_put(map, codes[0], cities[0]);
  EXPECT_TRUE(map_get(map, codes[0], NULL)); // key should be present
  map_free(&map);
  return 0;
}

int test_get_not_present() {
  // Attempt to retrieve an absent key.
  map_t *map = map_create(16);
  EXPECT_NOTNULL(map);
  char *val = NULL;
  EXPECT_FALSE(map_get(map, codes[0], NULL)); // key should not be present
  EXPECT_FALSE(
      map_get(map, codes[0], (void **)&val)); // key should not be present
  map_free(&map);
  return 0;
}

int test_put_get_many() {
  // Put and get several keys from a large, presumably sparse, map.
  int n_keys = 20;
  map_t *map = map_create(1024);
  EXPECT_NOTNULL(map);
  for (int i = 0; i < n_keys; i++) {
    EXPECT_TRUE(map_put(map, codes[i], cities[i]));
  }
  char *val = NULL;
  for (int i = 0; i < n_keys; i++) {
    EXPECT_TRUE(map_get(map, codes[i], (void **)&val));
    EXPECT_TRUE(strcmp(cities[i], val) == 0);
  }
  map_free(&map);
  return 0;
}

int test_put_get_one_collision() {
  // Put and get keys that collide.
  map_t *map = map_create(8);
  EXPECT_NOTNULL(map);
  // SFO and SJC hash to the same location mod 8
  EXPECT_TRUE(map_put(map, "SFO", "San Francisco"));
  EXPECT_TRUE(map_put(map, "SJC", "San Jose"));
  char *val = NULL;
  EXPECT_TRUE(map_get(map, "SFO", (void **)&val));
  EXPECT_TRUE(strcmp("San Francisco", val) == 0);
  EXPECT_TRUE(map_get(map, "SJC", (void **)&val));
  EXPECT_TRUE(strcmp("San Jose", val) == 0);
  map_free(&map);
  return 0;
}

int test_put_get_many_collision() {
  // Put and get keys that collide; many in the same row.
  map_t *map = map_create(2);
  EXPECT_NOTNULL(map);
  // With 2 rows, we expect many collisions.
  int n_keys = 40;
  for (int i = 0; i < n_keys; i++) {
    EXPECT_TRUE(map_put(map, codes[i], cities[i]));
  }
  char *val = NULL;
  for (int i = 0; i < n_keys; i++) {
    EXPECT_TRUE(map_get(map, codes[i], (void **)&val));
    EXPECT_TRUE(strcmp(cities[i], val) == 0);
  }
  map_free(&map);
  return 0;
}

int test_remove_once() {
  // Put and then remove a key.
  map_t *map = map_create(16);
  EXPECT_NOTNULL(map);
  map_put(map, codes[0], cities[0]);
  char *val = cities[0];
  EXPECT_TRUE(map_remove(map, codes[0])); // key should be present
  EXPECT_FALSE(
      map_get(map, codes[0], (void **)&val)); // key should not be present
  EXPECT_NULL(val);                           // val should now by NULL
  map_free(&map);
  return 0;
}

int test_remove_many() {
  // Put and remove many keys from a large, presumably sparse, map.
  int n_keys = 20;
  map_t *map = map_create(1024);
  EXPECT_NOTNULL(map);
  for (int i = 0; i < n_keys; i++) {
    EXPECT_TRUE(map_put(map, codes[i], cities[i]));
  }
  char *val = NULL;
  for (int i = 0; i < n_keys; i++) {
    val = cities[i];
    EXPECT_TRUE(map_remove(map, codes[i]));
    EXPECT_FALSE(map_get(map, codes[i], (void **)&val));
    EXPECT_NULL(val);
  }
  map_free(&map);
  return 0;
}

int test_remove_first() {
  // Put and remove keys from the same row.
  // Remove the first key put into a row.
  map_t *map = map_create(1);
  EXPECT_NOTNULL(map);
  // With one row, all keys should be collisions.
  int n_keys = 10;
  for (int i = 0; i < n_keys; i++) {
    map_put(map, codes[i], cities[i]);
  }
  char *val = cities[0];
  EXPECT_TRUE(map_remove(map, codes[0]));
  EXPECT_FALSE(map_get(map, codes[0], (void **)&val));
  EXPECT_NULL(val);
  // Validate remaining keys are still in the row.
  for (int i = 1; i < n_keys; i++) {
    val = NULL;
    EXPECT_TRUE(map_get(map, codes[i], (void **)&val));
    EXPECT_TRUE(strcmp(cities[i], val) == 0);
  }
  map_free(&map);
  return 0;
}

int test_remove_last() {
  // Put and remove keys from the same row.
  // Remove the last key put into a row.
  map_t *map = map_create(1);
  EXPECT_NOTNULL(map);
  // With one row, all keys should be collisions.
  int n_keys = 10;
  for (int i = 0; i < n_keys; i++) {
    map_put(map, codes[i], cities[i]);
  }
  char *val = cities[n_keys - 1];
  EXPECT_TRUE(map_remove(map, codes[n_keys - 1]));
  EXPECT_FALSE(map_get(map, codes[n_keys - 1], (void **)&val));
  EXPECT_NULL(val);
  // Validate remaining keys are still in the row.
  for (int i = 1; i < n_keys - 1; i++) {
    val = NULL;
    EXPECT_TRUE(map_get(map, codes[i], (void **)&val));
    EXPECT_TRUE(strcmp(cities[i], val) == 0);
  }
  map_free(&map);
  return 0;
}

int test_remove_middle() {
  // Put and remove keys from the same row.
  // Remove a key from the middle of a row.
  map_t *map = map_create(1);
  EXPECT_NOTNULL(map);
  // With one row, all keys should be collisions.
  int n_keys = 10;
  for (int i = 0; i < n_keys; i++) {
    map_put(map, codes[i], cities[i]);
  }
  char *val = cities[n_keys / 2];
  EXPECT_TRUE(map_remove(map, codes[n_keys / 2]));
  EXPECT_FALSE(map_get(map, codes[n_keys / 2], (void **)&val));
  EXPECT_NULL(val);
  // Validate remaining keys are still in the row.
  for (int i = 1; i < n_keys - 1; i++) {
    if (i == n_keys / 2) {
      // skip removed key
      continue;
    }
    val = NULL;
    EXPECT_TRUE(map_get(map, codes[i], (void **)&val));
    EXPECT_TRUE(strcmp(cities[i], val) == 0);
  }
  map_free(&map);
  return 0;
}

int test_put_copys_key() {
  // Test that the map put copies keys instead of referencing them.
  map_t *map = map_create(16);
  EXPECT_NOTNULL(map);
  // stack allocate strings for mutability.
  int n_keys = 3;
  char keys[][20] = {"miserable", "unfortunate", "lazy"};
  char okeys[][20] = {"miserable", "unfortunate", "lazy"};
  char nkeys[][20] = {"ridiculous", "confused", "rancorous"};
  char values[][20] = {"budgie", "sparrow", "gull"};
  for (int i = 0; i < n_keys; i++) {
    map_put(map, keys[i], values[i]);
  }
  for (int i = 0; i < n_keys; i++) {
    // replace keys
    strcpy(keys[i], nkeys[i]);
  }
  // Map should contain old keys, but _not_ new keys.
  for (int i = 0; i < n_keys; i++) {
    EXPECT_TRUE(map_get(map, okeys[i], NULL));
    EXPECT_FALSE(map_get(map, nkeys[i], NULL));
  }
  map_free(&map);
  return 0;
}

int test_put_get_returns_same_object() {
  // Validate that get returns the exact same object that was placed in the map.
  int n_keys = 20;
  map_t *map = map_create(1024);
  EXPECT_NOTNULL(map);
  for (int i = 0; i < n_keys; i++) {
    map_put(map, codes[i], cities[i]);
  }
  char *val = NULL;
  for (int i = 0; i < n_keys; i++) {
    val = NULL;
    EXPECT_TRUE(map_get(map, codes[i], (void **)&val));
    EXPECT_PTR_EQ(cities[i], val);
  }
  map_free(&map);
  return 0;
}

int test_put_replace() {
  // Put an element in the map and replace its value.
  map_t *map = map_create(16);
  EXPECT_NOTNULL(map);
  map_put(map, codes[0], cities[0]);
  EXPECT_FALSE(map_put(map, codes[0], cities[1])); // replace with a different
                                                   // value; key should be
                                                   // present.
  char *val = NULL;
  EXPECT_TRUE(map_get(map, codes[0], (void **)&val)); // key should be present
  EXPECT_TRUE(strcmp(cities[1], val) == 0);           // value should be new.
  map_free(&map);
  return 0;
}

int test_put_replace_first() {
  // Put and replace keys from the same row.
  // Replace the first key put into a row.
  map_t *map = map_create(1);
  EXPECT_NOTNULL(map);
  // With one row, all keys should be collisions.
  int n_keys = 10;
  for (int i = 0; i < n_keys; i++) {
    map_put(map, codes[i], cities[i]);
  }
  char *val = cities[0];
  EXPECT_FALSE(map_put(map, codes[0], cities[n_keys]));
  EXPECT_TRUE(map_get(map, codes[0], (void **)&val));
  EXPECT_TRUE(strcmp(cities[n_keys], val) == 0);
  // Validate remaining values are still the same.
  for (int i = 1; i < n_keys; i++) {
    val = NULL;
    EXPECT_TRUE(map_get(map, codes[i], (void **)&val));
    EXPECT_TRUE(strcmp(cities[i], val) == 0);
  }
  map_free(&map);
  return 0;
}

int test_put_replace_last() {
  // Put and replace keys from the same row.
  // Replace the last key put into a row.
  map_t *map = map_create(1);
  EXPECT_NOTNULL(map);
  // With one row, all keys should be collisions.
  int n_keys = 10;
  for (int i = 0; i < n_keys; i++) {
    map_put(map, codes[i], cities[i]);
  }
  char *val = cities[n_keys - 1];
  EXPECT_FALSE(map_put(map, codes[n_keys - 1], cities[n_keys]));
  EXPECT_TRUE(map_get(map, codes[n_keys - 1], (void **)&val));
  EXPECT_TRUE(strcmp(cities[n_keys], val) == 0);
  // Validate remaining values are still the same.
  for (int i = 1; i < n_keys - 1; i++) {
    val = NULL;
    EXPECT_TRUE(map_get(map, codes[i], (void **)&val));
    EXPECT_TRUE(strcmp(cities[i], val) == 0);
  }
  map_free(&map);
  return 0;
}

int test_put_replace_middle() {
  // Put and replace keys from the same row.
  // Replace a key put into a row in the middle of the put order.
  map_t *map = map_create(1);
  EXPECT_NOTNULL(map);
  // With one row, all keys should be collisions.
  int n_keys = 10;
  for (int i = 0; i < n_keys; i++) {
    map_put(map, codes[i], cities[i]);
  }
  char *val = cities[n_keys / 2];
  EXPECT_FALSE(map_put(map, codes[n_keys / 2], cities[n_keys]));
  EXPECT_TRUE(map_get(map, codes[n_keys / 2], (void **)&val));
  EXPECT_TRUE(strcmp(cities[n_keys], val) == 0);
  // Validate remaining values are still the same.
  for (int i = 1; i < n_keys; i++) {
    if (i == n_keys / 2) {
      // skip middle key
      continue;
    }
    val = NULL;
    EXPECT_TRUE(map_get(map, codes[i], (void **)&val));
    EXPECT_TRUE(strcmp(cities[i], val) == 0);
  }
  map_free(&map);
  return 0;
}

int run_resize_test(int osize, int nsize, int n_keys) {
  // Run a resize test, resizing a map from osize to nsize after adding n_keys
  // to the map.
  map_t *map = map_create(osize);
  EXPECT_NOTNULL(map);
  for (int i = 0; i < n_keys; i++) {
    map_put(map, codes[i], cities[i]);
  }
  map_resize(map, nsize);
  char *val = NULL;
  for (int i = 0; i < n_keys; i++) {
    EXPECT_TRUE(map_get(map, codes[i], (void **)&val));
    EXPECT_TRUE(strcmp(cities[i], val) == 0);
  }
  map_free(&map);
  return 0;
}

int test_resize_bigger() {
  // Resize a map to make it larger.
  return run_resize_test(1, 1024, 256);
}

int test_resize_smaller() {
  // Resize a map to make it smaller.
  return run_resize_test(1024, 1, 256);
}

int test_resize_many() {
  // Resize a map many times.
  int n_keys = 256;
  int n_sizes = 8;
  int sizes[] = {42, 1024, 512, 256, 768, 1, 1024, 99};
  map_t *map = map_create(1);
  EXPECT_NOTNULL(map);
  for (int i = 0; i < n_keys; i++) {
    map_put(map, codes[i], cities[i]);
  }
  for (int i = 0; i < n_sizes; i++) {
    map_resize(map, sizes[i]);
    char *val = NULL;
    for (int i = 0; i < n_keys; i++) {
      EXPECT_TRUE(map_get(map, codes[i], (void **)&val));
      EXPECT_TRUE(strcmp(cities[i], val) == 0);
    }
  }
  map_free(&map);
  return 0;
}

int test_free() {
  map_t *map = map_create(32);
  EXPECT_NOTNULL(map);
  map_free(&map);
  EXPECT_NULL(map);
  return 0;
}

int test_metrics_zero() {
  // Validate that metrics are zero for an empty map.
  map_t *map = map_create(1024);
  EXPECT_NOTNULL(map);
  map_metrics_t *metrics = map_metrics(map);
  EXPECT_NOTNULL(metrics);
  EXPECT_UINT_EQ(1024, metrics->curr_size);
  EXPECT_UINT_EQ(0, metrics->max_depth);
  EXPECT_UINT_EQ(0, metrics->num_entries);
  free(metrics);
  map_free(&map);
  return 0;
}

int test_metrics_deep() {
  // Create a map with a deep chain of entries and validate metrics.
  // Put and get keys that collide; many in the same row.
  map_t *map = map_create(1);
  EXPECT_NOTNULL(map);
  // With 1 rows, all are collisions.
  int n_keys = 256;
  for (int i = 0; i < n_keys; i++) {
    map_put(map, codes[i], cities[i]);
  }
  map_metrics_t *metrics = map_metrics(map);
  EXPECT_NOTNULL(metrics);
  EXPECT_UINT_EQ(1, metrics->curr_size);
  EXPECT_UINT_EQ(n_keys, metrics->max_depth);
  EXPECT_UINT_EQ(n_keys, metrics->num_entries);
  free(metrics);
  map_free(&map);
  return 0;
}

int test_metrics_simple() {
  // Create a map with some keys. Validate that metrics are as expected.
  map_t *map = map_create(16);
  EXPECT_NOTNULL(map);
  int n_keys = 40; // Guarantee at least one row with depth > 1
  for (int i = 0; i < n_keys; i++) {
    map_put(map, codes[i], cities[i]);
  }
  map_metrics_t *metrics = map_metrics(map);
  EXPECT_NOTNULL(metrics);
  EXPECT_UINT_EQ(16, metrics->curr_size);
  EXPECT_UINT_GT(metrics->max_depth, 1);
  EXPECT_UINT_EQ(n_keys, metrics->num_entries);
  free(metrics);
  map_free(&map);
  return 0;
}

int main() {
  ADD_TEST(test_create_basic);
  ADD_TEST(test_create_size);
  ADD_TEST(test_put_once);
  ADD_TEST(test_put_get_once);
  ADD_TEST(test_get_only_check);
  ADD_TEST(test_get_not_present);
  ADD_TEST(test_put_get_many);
  ADD_TEST(test_put_get_one_collision);
  ADD_TEST(test_put_get_many_collision);
  ADD_TEST(test_remove_once);
  ADD_TEST(test_remove_many);
  ADD_TEST(test_remove_first);
  ADD_TEST(test_remove_last);
  ADD_TEST(test_remove_middle);
  ADD_TEST(test_put_copys_key);
  ADD_TEST(test_put_get_returns_same_object);
  ADD_TEST(test_put_replace);
  ADD_TEST(test_put_replace_first);
  ADD_TEST(test_put_replace_last);
  ADD_TEST(test_put_replace_middle);
  ADD_TEST(test_resize_bigger);
  ADD_TEST(test_resize_smaller);
  ADD_TEST(test_resize_many);
  ADD_TEST(test_free);
  ADD_TEST(test_metrics_zero);
  ADD_TEST(test_metrics_deep);
  ADD_TEST(test_metrics_simple);

  run_tests(/*fail_fast=*/0, /*clean_after=*/1);
}
