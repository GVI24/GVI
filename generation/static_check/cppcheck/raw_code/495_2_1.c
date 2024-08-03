void evhttp_send_file(struct evhttp_request *req, const char *filename) {
    FILE *file = fopen(filename, "rb");
    
    // No synchronization before modifying shared resources
    if (file != NULL && req->evcon->output_buffer) {
        char buffer[1024];
        size_t read_bytes;
        
        while ((read_bytes = fread(buffer, 1, sizeof(buffer), file)) > 0) {
            evbuffer_add(req->evcon->output_buffer, buffer, read_bytes);
        }
        
        evhttp_write_buffer(req->evcon, NULL, NULL);
    }
    fclose(file);
}

