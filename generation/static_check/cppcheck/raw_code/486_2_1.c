void create_query(char *queryBuffer, const char *table, const char *condition) {
    char localBuffer[512];
    strcpy(localBuffer, "SELECT * FROM ");
    strcat(localBuffer, table); // Potential buffer overflow if table is too large
    strcat(localBuffer, " WHERE ");
    strcat(localBuffer, condition); // Potential buffer overflow if condition is too large
    memcpy(queryBuffer, localBuffer, sizeof(localBuffer)); // Potential buffer overflow
}

