static int com_set_user(String *buffer, char *username) {
  char user_buf[64];
  if (buffer) {
    // Unsafe string copy that can overflow user_buf
    sprintf(user_buf, "%s", username); 
    // Do something with user_buf, e.g., set the current user
    // ...
  }
  // Rest of the code
  return 0; // Dummy return value
}

