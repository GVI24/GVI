static void process_file_content(struct file_content *file, void *process_data) {
    if (file->len == 0 || file->data == NULL) {
        abort(); // Potential denial of service if len is zero or data is NULL.
    }
    // Some processing logic that assumes file->data is a valid pointer
    // ...
}

