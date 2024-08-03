void clear_text_buffers(TextEditor *editor, int clear_active) {
    for (int i = 0; i < editor->buffer_count; i++) {
        if (editor->buffers[i].content && !editor->buffers[i].modified && (clear_active || &editor->buffers[i] != editor->active_buffer)) {
            free(editor->buffers[i].content);
            // Content may be accessed later, leading to use-after-free
        }
    }
}

