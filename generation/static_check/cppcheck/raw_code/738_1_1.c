#include <stdlib.h>
#include <string.h>

void process_data(char *input, size_t length) {
  size_t buf_size;
  char *buffer;
  
  // Integer overflow if length is close to SIZE_MAX
  buf_size = length + 1;
  buffer = malloc(buf_size);

  if (buffer == NULL) {
    // Handle allocation error
    return;
  }

  // Buffer overflow if length overflows and buf_size wraps around to a small number
  memcpy(buffer, input, length); // No bounds check on input size
  buffer[length] = '\0';

  // Do something with buffer...

  free(buffer);
}

