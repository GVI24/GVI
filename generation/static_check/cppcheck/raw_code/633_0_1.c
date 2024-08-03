struct user_preferences * user_prefs_load ( pool_t pool , const char * username ) {
    struct user_preferences_parser_info * info;
    void ** sets;
    unsigned int count = 0;
    
    // Normally, the size of info->items should be checked.
    sets = p_new(pool, void *, count);
    while (info->items[count] != NULL) {
        sets[count] = user_preferences_dup(pool, info->items[count]);
        count++;
    }

    // There is no bounds checking on info->items
    // This can cause a buffer overflow if count exceeds the allocated size for 'sets'
    return sets[0];
}

