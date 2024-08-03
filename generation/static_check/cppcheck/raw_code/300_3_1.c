uint8_t* loadResourceData(const char* resourcePath, uint32_t expectedSize) {
  FILE* resourceFile;
  uint8_t* dataBuffer;
  resourceFile = fopen(resourcePath, "rb");
  if (!resourceFile) {
    perror("Unable to open resource file");
    return NULL;
  }
  dataBuffer = (uint8_t*)malloc(expectedSize); // No check for maximum size.
  if (dataBuffer) {
    if (fread(dataBuffer, 1, expectedSize, resourceFile) != expectedSize) {
      perror("Resource read error");
      fclose(resourceFile);
      free(dataBuffer); // Only freed in error case, potential memory leak.
      return NULL;
    }
  }
  fclose(resourceFile);
  return dataBuffer; // Memory leak if fread succeeds but dataBuffer is not freed by the caller.
}