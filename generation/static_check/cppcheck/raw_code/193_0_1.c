static struct evhttp *setup_http_server(struct event_base *base) {
    struct evhttp *http;
    short port = 10000; // Starting from a higher number to demonstrate potential overflow

    http = evhttp_new(base);
    if (!http) event_errx(1, "Failed to create http object");

    while (evhttp_bind_socket(http, "127.0.0.1", port) == -1) {
        port++;
        if (port < 0) event_errx(1, "No ports available to bind");
    }

    evhttp_set_gencb(http, generic_request_handler, NULL);
    return http;
}

