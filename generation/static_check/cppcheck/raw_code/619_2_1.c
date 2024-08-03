void add_file_to_user(int argc, char *argv[]) {
    user_files ufiles;
    char *username, *filename;
    
    if (argc < 3) {
        printf("Usage: add_file_to_user <username> <filename>\n");
        return;
    }
    
    username = argv[1];
    filename = argv[2];
    
    if (load_user_files(username, &ufiles)) {
        if (!add_file(&ufiles, filename)) {
            printf("Failed to add file '%s' to user '%s'.\n", filename, username);
            // Error path without cleanup for ufiles
            return;
        }
        save_user_files(username, &ufiles);
        printf("File '%s' added to user '%s'.\n", filename, username);
    } else {
        printf("User '%s' not found.\n", username);
        // Missing free operation for ufiles
    }
    
cleanup:
    free_user_files(&ufiles);
}

