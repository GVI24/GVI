void file_path_concat(char *file_path, const char *folder, const char *file_name) {
    size_t folder_len = strlen(folder);
    size_t file_name_len = strlen(file_name);
    const size_t max_path = 260; // Typical max path length on Windows systems
    // Vulnerable to buffer overflow if folder_len + file_name_len + 1 > max_path
    memcpy(file_path, folder, folder_len);
    memcpy(file_path + folder_len, "/", 1);
    memcpy(file_path + folder_len + 1, file_name, file_name_len + 1); // Includes null terminator
}