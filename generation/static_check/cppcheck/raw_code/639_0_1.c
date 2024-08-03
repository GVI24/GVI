int read_header_v1(struct file_system *fs, void *file_handle, struct file_header *header) {
  unsigned char header_buf[HEADER_SIZE];
  if (fs->read(file_handle, header_buf, HEADER_SIZE) != HEADER_SIZE) {
    return -1;
  }

  header->signature = *(unsigned int *)header_buf;
  
  header->filename = fs->alloc(MAX_FILENAME_SIZE);
  if (!header->filename) {
    return -1;
  }
  
  memcpy(header->filename, header_buf + 4, MAX_FILENAME_SIZE);  // Potential buffer overflow
  header->filename[MAX_FILENAME_SIZE - 1] = '\0';
  
  header->data_length = *(int *)(header_buf + 4 + MAX_FILENAME_SIZE);
  
  return 0;
}

