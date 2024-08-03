void parse_header_field(const char *header, size_t header_len) {
  const char *header_value = strchr(header, ':');
  if (header_value == NULL) {
    // No colon found - header is invalid, but should handle error
    return;
  }
  header_value += 1; // Move past the colon
  while (*header_value == ' ') {
    header_value++; // Skip whitespace
  }
  size_t value_len = header_len - (header_value - header);
  char field_value[128];
  if (value_len >= sizeof(field_value)) {
    // If value_len is miscalculated, it can cause a buffer overflow
    return;
  }
  strncpy(field_value, header_value, value_len);
  field_value[value_len] = '\0'; // Ensure null-termination
  // Use the parsed field_value
}