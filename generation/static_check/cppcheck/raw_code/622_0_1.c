void copy_header_value(char *dest, const char *src, size_t dest_size) {
  size_t src_len = strlen(src);
  if (src_len >= dest_size) {
    // Incorrect handling of buffer size -- can lead to buffer overflow
    return;
  }
  // Vulnerable as src_len could cause dest to overflow
  memcpy(dest, src, src_len + 1);
}

