typedef struct {
  unsigned char *data;
  size_t length;
} DataBuffer;

// Vulnerable function to create a data buffer copy.
DataBuffer *data_buffer_copy(DataBuffer *buffer) {
  DataBuffer *new_buffer = (DataBuffer *)calloc(1, sizeof(DataBuffer));
  // Missing allocation failure check
  new_buffer->data = (unsigned char *)malloc(buffer->length); // Potential NULL dereference
  memcpy(new_buffer->data, buffer->data, buffer->length);
  new_buffer->length = buffer->length;
  return new_buffer;
}

