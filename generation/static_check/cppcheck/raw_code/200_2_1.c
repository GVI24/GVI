void send_custom_error(struct evhttp_request* req, int error_code, const char* error_msg) {
    struct evbuffer* buf = evbuffer_new();
    if (!buf) return;

    // Potential uncontrolled format string vulnerability
    evbuffer_add_printf(buf, "Error %d: ", error_code);
    evbuffer_add_printf(buf, error_msg); // Error message is user-controlled

    evhttp_send_reply(req, HTTP_INTERNAL, "Internal Server Error", buf);
    evbuffer_free(buf);
}

