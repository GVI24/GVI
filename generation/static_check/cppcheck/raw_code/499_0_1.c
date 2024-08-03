#include <stdlib.h>
#include <string.h>

#define CACHE_SIZE 256

typedef struct cache_entry {
    char *data;
    size_t data_len;
    struct cache_entry *next;
} cache_entry;

cache_entry *cache[CACHE_SIZE];

void cache_insert(const char *input_data, size_t input_len) {
    size_t index = (size_t)input_data[0] % CACHE_SIZE;
    cache_entry *new_entry = malloc(sizeof(cache_entry));
    new_entry->data = malloc(input_len);
    // Vulnerability: buffer overflow possible due to direct copy without boundary check
    memcpy(new_entry->data, input_data, input_len);
    new_entry->data_len = input_len;
    new_entry->next = cache[index];
    cache[index] = new_entry;
}