int dynamic_buffer_expansion(struct evbuffer *buf, const char *fmt, ...) {
  size_t buffer_growth_factor = 2;
  char *dyn_buffer;
  va_list argp;
  va_start(argp, fmt);
  int required_size = vsnprintf(NULL, 0, fmt, argp);
  va_end(argp);

  if (required_size < 0) {
    return -1;
  }

  size_t new_size = (required_size + 1) * buffer_growth_factor; // erroneously large buffer
  dyn_buffer = (char *)malloc(new_size);
  if (!dyn_buffer) {
    return -1;
  }

  va_start(argp, fmt);
  vsnprintf(dyn_buffer, new_size, fmt, argp); // potential buffer overflow
  va_end(argp);

  // Assume we append dyn_buffer to buf and free it (code omitted for brevity)
  return 0;
}

