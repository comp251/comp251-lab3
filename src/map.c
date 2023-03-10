#include "map.h"

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fnv64.h"

// Uncomment #define DEBUG and comment out the following to turn on DEBUG_PRINT
// statements.
#undef DEBUG
// #define DEBUG

// Definition of DEBUG_PRINT macro. Whenever you want to insert debug print
// statements, you should use this macro. It behaves _exactly_ like printf. If
// you want to print the variables key and hashed_key, for example,
// you could do the following:
//
//    DEBUG_PRINT("key: %s; hash: %016lx\n", key, hashed_key);
//
// This will behave like printf when the #define DEBUG statement above is
// uncommented. When the #undef DEBUG statement is uncommented, nothing will be
// printed. You should use DEBUG when you are trying to drill down into a
// problem, and then turn off DEBUG when you are running your final experiments
// (since these perform millions of operations on your map).
#ifdef DEBUG
#define DEBUG_PRINT(format, args...)                                           \
  fprintf(stderr, "D %s:%d:%s(): " format, __FILE__, __LINE__, __func__, ##args)
#else
#define DEBUG_PRINT(fmt, args...) // no-op
#endif

// Entry struct.
typedef struct entry_t {
  struct entry_t *next; // next entry in linked list
  struct entry_t *prev; // previous entry
  char *key;            // string key
  uint64_t hkey;        // 64-bit hash of key
  void *value;          // value stored for the key
} entry_t;

// Map struct.
struct map_t {
  entry_t **entries; // array of pointers to entries
  uint32_t n;        // size of entries array
};

map_t *map_create(uint32_t init_size) {
  // TODO: implement me
  return NULL;
}

map_metrics_t *map_metrics(map_t *map) {
  // TODO: implement me
  return NULL;
}

void map_free(map_t **map) {
  // TODO: implement me
}

int map_put(map_t *map, const char *key, void *new_value) {
  // TODO: implement me
  return 0;
}

int map_remove(map_t *map, const char *key) {
  // TODO: implement me
  return 0;
}

int map_get(map_t *map, const char *key, void **value_ptr) {
  // TODO: implement me
  return 0;
}

void map_resize(map_t *map, uint32_t new_size) {
  // TODO: implement me
}

void map_debug(map_t *map) {
  // TODO: implement me
}

void map_apply(map_t *map, void *apply_fn(const char *key, void *value)) {
  for (int i = 0; i < map->n; i++) {
    // for each entry
    entry_t *cur = map->entries[i];
    while (cur) {
      // traverse linked list of entries, applying along the way
      cur->value = apply_fn(cur->key, cur->value);
      cur = cur->next;
    }
  }
}

uint32_t map_size(map_t *map) { return map->n; }
