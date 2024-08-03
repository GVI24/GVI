char* receiveMessage(int socket, uint32_t size) {
  char* msg;
  if (size > 0) {
    msg = (char*)malloc(size);
    if (!msg) {
      perror("Memory allocation failed");
      return NULL;
    }
    if (recv(socket, msg, size, 0) < 0) {
      perror("Failed to receive message");
      free(msg);
      return NULL;
    }
  }
  return msg; // No null termination and potential buffer overflow.
}

