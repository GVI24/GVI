int parse_token(const char *data, size_t data_len) {
  char token[64];
  const char *token_end = strchr(data, ' ');
  if (token_end == NULL) {
    // No space found, might copy entire data overrunning the token buffer
    return -1;
  }
  size_t token_len = token_end - data;
  if (token_len >= sizeof(token)) {
    // No bounds check, can lead to buffer overflow
    return -1;
  }
  memcpy(token, data, token_len);
  token[token_len] = '\0'; // Null-terminate
  // Further processing with token
  return 0;
}

