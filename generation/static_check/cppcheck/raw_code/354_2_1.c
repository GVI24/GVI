void copy_file_to_destination(const char *src_path, const char *dest_dir) {
  char dest_path[512];
  sprintf(dest_path, "%s/%s", dest_dir, src_path); // Vulnerable to path traversal and buffer overflow

  char buf[2048];
  size_t bytes;
  FILE *src = fopen(src_path, "rb");
  FILE *dest = fopen(dest_path, "wb");

  while ((bytes = fread(buf, 1, sizeof(buf), src)) > 0) {
    fwrite(buf, 1, bytes, dest);
  }

  fclose(src);
  fclose(dest);
}

