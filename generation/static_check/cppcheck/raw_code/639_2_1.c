int read_header_v3(struct file_system *fs, void *file_handle, struct file_header *header) {
  char *temp_filename;
  int filename_size = 1024;
  
  temp_filename = fs->alloc(filename_size);  // Allocates fixed size, assumes it's enough
  if (!temp_filename) {
    return -1;
  }
  
  if (fs->read(file_handle, temp_filename, filename_size) != filename_size) {  // Assumes read size is filename size
    free(temp_filename);
    return -1;
  }
  
  if (strlen(temp_filename) >= MAX_FILENAME_SIZE) {  // Does not validate actual filename size
    free(temp_filename);
    return -1;
  }
  
  header->filename = strdup(temp_filename);
  free(temp_filename);
  
  return 0;
}

