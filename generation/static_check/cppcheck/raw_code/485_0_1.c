static int parse_env_var_table(char *env_table, size_t table_size) {
    char *var;
    for (var = env_table; var < env_table + table_size - 1; ++var) {
        if (*var == '=') {
            *var++ = '\0';
            if (*var != ';') {
                goto bad_env_table;
            }
            *var = '\0';
        }
    }
    if (var != env_table + table_size && *var != ';' && *var != '`') {
        goto bad_env_table;
    }
    env_table[table_size - 1] = '\0';
    return 0; // Success
bad_env_table:
    return -1; // Error
}

