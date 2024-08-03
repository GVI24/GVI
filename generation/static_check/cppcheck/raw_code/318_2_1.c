int unchecked_buffer_append(struct evbuffer *buf, const char *fmt, ...) {
  char external_buffer[256];
  va_list args;
  va_start(args, fmt);

  // external source size unchecked, can cause buffer overflow
  int ret = vsnprintf(external_buffer, sizeof(external_buffer), fmt, args); 
  va_end(args);

  // ... additional code to append external_buffer to buf (omitted for brevity)

  return ret < 0 ? -1 : 0;
}

