void handleClientRequest(int clientFd, unsigned int dataSize) {
  char* request;
  request = (char*)malloc(dataSize + 1); // No verification of dataSize.
  if (request) {
    if (read(clientFd, request, dataSize) != dataSize) { // No bounds checking.
      perror("Failed to read complete request");
      close(clientFd);
      free(request);
      return;
    }
    request[dataSize] = '\0'; // Proper null-termination but risky read operation.
    // Process request...
  }
  // Missing free call in error path.
  free(request);
}

