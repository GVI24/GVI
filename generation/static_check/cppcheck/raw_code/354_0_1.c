void process_image_file(char *input_file_path) {
  char output_file_path[256];
  strcpy(output_file_path, input_file_path);
  strcat(output_file_path, ".processed"); // Potential buffer overflow

  // Simulate image processing
  printf("Processing image file: %s\n", output_file_path);
  // ... processing logic ...
}

