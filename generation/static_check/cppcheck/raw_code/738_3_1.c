#include <string.h>

void copy_data(const char *src, char *dst, size_t copy_size) {
  const char *end = src + copy_size;

  // Unsafe pointer arithmetic without bounds checking can lead to out-of-bounds read
  while (src < end) {
    *dst = *src;
    dst++;
    src++;

    // Potential for out-of-bounds write if dst buffer is smaller than copy_size
  }
}