static void compile_and_deploy_code(void) {
    int code_id;
    for (code_id = 0; code_id < code_repository.count; code_id++) {
        char compile_cmd[1024];
        CodeEntry *code_entry = &code_repository.entries[code_id];
        printf("Compiling code for entry: %s\n", code_entry->entry_name);

        // Vulnerability: Creating a shell command from user-submitted code entry name
        snprintf(compile_cmd, sizeof(compile_cmd),
                 "gcc /src/%s -o /bin/%s && /deploy.sh /bin/%s",
                 code_entry->file_name, code_entry->entry_name, code_entry->entry_name);

        // Executing the untrusted compile and deploy command
        system(compile_cmd);
    }
}

