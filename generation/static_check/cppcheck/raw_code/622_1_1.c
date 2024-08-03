int process_user_input(const char *input, size_t input_len) {
  char buffer[256];
  if (input_len > 256) {
    // Integer overflow vulnerability due to lack of proper validation
    return -1;
  }
  // Potential buffer overflow if input_len is not what is expected
  strncpy(buffer, input, input_len);
  buffer[input_len] = '\0'; // Null-terminate explicitly
  // Do something with buffer
  return 0;
}

