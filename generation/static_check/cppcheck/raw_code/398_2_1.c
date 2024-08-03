static int com_execute_command(String *buffer, char *command) {
  char cmd_buf[128];
  if (buffer) {
    // Unsafe copy that does not check the size of the command
    strcpy(cmd_buf, command); 
    // Execute the command, could run arbitrary code if command is too large
    // ...
  }
  // Rest of the code
  return 0; // Dummy return value
}

