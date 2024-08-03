#define USER_BUFFER_SIZE 512
void process_user_data(int user_id, const char *user_data) {
    char data_buffer[USER_BUFFER_SIZE];
    char *data_ptr = data_buffer;
    
    // Unsafe: if user_data length exceeds the buffer, it will overflow
    snprintf(data_ptr, USER_BUFFER_SIZE, "User ID: %d, Data: %s", user_id, user_data);
    
    // Code to process or store user data
    // ...
}

