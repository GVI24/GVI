int read_header_v4(struct file_system *fs, void *file_handle, struct file_header *header) {
  unsigned char extension_buf[FILE_EXTENSION_SIZE];
  int status;
  
  header->filename = fs->alloc(MAX_FILENAME_SIZE);
  if (!header->filename) {
    return -1;
  }
  
  status = fs->read(file_handle, header->filename, MAX_FILENAME_SIZE);
  if (status < 0 || status != MAX_FILENAME_SIZE) {
    return -1; // Memory leak, allocated filename is not freed on error
  }
  
  status = fs->read(file_handle, extension_buf, FILE_EXTENSION_SIZE);
  if (status < 0 || status != FILE_EXTENSION_SIZE) {
    return -1; // Memory leak, allocated filename is not freed on error
  }

  memcpy(header->extension, extension_buf, FILE_EXTENSION_SIZE);
  header->extension[FILE_EXTENSION_SIZE] = '\0';
  
  return 0;
}