void get_user_input() {
    char user_input[100];
    printf("Enter input: ");
    scanf("%s", user_input); // Vulnerability: unbounded string input
    // Omitted: Code to handle user_input
}