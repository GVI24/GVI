void get_user_data(char *user_input) {
    // Vulnerability: Unsafe use of gets() can lead to buffer overflow if input exceeds buffer size.
    printf("Enter your data: ");
    gets(user_input); // Dangerous: gets() does not check the length of the input.
}