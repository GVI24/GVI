void read_text_file(char *file_path) {
  char buffer[1024];
  FILE *file = fopen(file_path, "r");
  if (!file) {
    perror("Error opening file");
    return;
  }
  fread(buffer, 1024, 1, file); // No check for actual file size
  fclose(file);

  printf("File content:\n%s\n", buffer);
  // ... further processing logic ...
}

