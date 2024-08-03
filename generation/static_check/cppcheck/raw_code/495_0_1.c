void evhttp_start_read(struct evhttp_request *req) {
    // Pretend operation that marks the request to be free'd
    mark_request_for_deletion(req); 

    // Use-after-free: Request might be deleted before or during this use
    if (req->evcon->reading) {
        evbuffer_add(req->evcon->input_buffer, "Reading started\r\n", 17);
        evhttp_read_buffer(req->evcon, NULL, NULL);
    }
}

