int read_header_v2(struct file_system *fs, void *file_handle, struct file_header *header) {
  unsigned char size_buf[4];
  int name_size;
  
  if (fs->read(file_handle, size_buf, 4) != 4) {
    return -1;
  }
  
  name_size = *(int *)size_buf;
  if (name_size < 0) {
    return -1;
  }
  
  header->filename = fs->alloc(name_size + 1);  // Integer overflow may occur here
  if (!header->filename) {
    return -1;
  }
  
  if (fs->read(file_handle, header->filename, name_size) != name_size) {
    free(header->filename);
    return -1;
  }
  
  header->filename[name_size] = '\0';
  
  return 0;
}

