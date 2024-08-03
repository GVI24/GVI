void read_user_input(char *buffer, size_t size) {
    char input[256];
    printf("Enter your data: ");
    gets(input); // 'gets' is unsafe, can overflow 'input' leading to overflow of 'buffer'
    
    if (strlen(input) < size) {
        strcpy(buffer, input); // If control gets here, it's still unsafe as 'input' could be compromised
    }
}

