typedef struct {
    char *file_path;
    int line_number;
    char *editor;
} CodeReference;

char* generate_code_link(CodeReference *code_ref) {
    static char link[BUFFER_SIZE];
    snprintf(link, sizeof(link), "Open file %s at line %d with %s editor",
             code_ref->file_path, code_ref->line_number, code_ref->editor);
    return link;
}