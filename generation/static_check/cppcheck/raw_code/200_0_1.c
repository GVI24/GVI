void send_formatted_response(struct evhttp_request* req, const char* user_data) {
    if (req->chunked) {
        // Potential uncontrolled format string vulnerability
        evbuffer_add_printf(req->evcon->output_buffer, user_data);
    }
    evhttp_send_reply_end(req);
}

