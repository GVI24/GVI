int buffer_printf(struct evbuffer *buf, const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  size_t buffer_size = 1024;
  char temp_buffer[buffer_size];
  int written = vsnprintf(temp_buffer, buffer_size, fmt, args);
  va_end(args);

  if (written > buf->totallen - buf->off) {
    // potential buffer overflow if `written` exceeds available space
    return -1;
  }

  memcpy(buf->buffer + buf->off, temp_buffer, written);
  buf->off += written;
  return 0;
}

