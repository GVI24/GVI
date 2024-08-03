#include <stdio.h>
#include <stdlib.h>

void process_data(const char *filename) {
  FILE *file = fopen(filename, "r");
  // Vulnerability: File not closed on error path, leading to resource leak
  if (!file) {
    fprintf(stderr, "Could not open file: %s\n", filename);
    return; // Missing fclose leads to resource leak
  }

  // Perform some operations with file
  // ...

  fclose(file); // Only closed on the non-error path
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <data_file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  process_data(argv[1]);
  return EXIT_SUCCESS;
}