#include <stdio.h>
#include <stdlib.h>

void process_file(const char *filename) {
  char buffer[1024];
  FILE *file = fopen(filename, "r");
  if (!file) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }
  
  // Vulnerability: No validation for file content leading to potential overflow
  fread(buffer, 1, sizeof(buffer) * 2, file);

  printf("File content processed\n");
  fclose(file);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
    return EXIT_FAILURE;
  }

  process_file(argv[1]);
  return EXIT_SUCCESS;
}