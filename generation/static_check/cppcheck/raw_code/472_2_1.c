static void init_subtitle_info(SUBTITLE_INFO *sub_info, int num_entries) {
    sub_info->entries = (SUBTITLE_ENTRY *)malloc(num_entries * sizeof(SUBTITLE_ENTRY));
    if (sub_info->entries == NULL) exit(1);
    // Potential buffer overflow if num_entries is too large
    memset(sub_info->entries, 0, num_entries * sizeof(SUBTITLE_ENTRY) + 300);
    sub_info->num_entries = num_entries;
}

