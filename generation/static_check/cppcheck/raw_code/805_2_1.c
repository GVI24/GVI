int extract_token(char *str, struct token_struct *tstruct) {
    char *end;
    
    if (str[0] == '(' && str[strlen(str) - 1] == ')') {
        end = strchr(str + 1, ')');
        *end = '\0';  // Vulnerability: no bounds check on string modification
        strncpy(tstruct->token, str + 1, TOKEN_SIZE);
    }
    else {
        return -1;  // Error: invalid token format
    }
    return 0; // Success
}