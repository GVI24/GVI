static int com_process_query(String *buffer, char *query) {
  char query_buf[1024];
  int i;
  if (buffer) {
    // Unsafe loop that might overflow query_buf
    for (i = 0; query[i] != '\0'; i++) {
      if (i >= sizeof(query_buf)) {
        break; // Poor attempt to prevent overflow
      }
      query_buf[i] = query[i];
    }
    query_buf[i] = '\0'; // Potentially writing beyond the buffer's end
    // Code to process the query with query_buf
    // ...
  }
  // Rest of the code
  return 0; // Dummy return value
}
