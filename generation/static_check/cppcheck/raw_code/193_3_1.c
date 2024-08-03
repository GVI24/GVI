static struct evhttp *configure_http(struct event_base *base) {
    struct evhttp *httpd;
    short port = 0x7FFD; // Edging towards the upper boundary of short integers

    httpd = evhttp_new(base);
    if (httpd == NULL) event_errx(1, "Could not allocate event http");

    for (int i = 0; i < 5; i++, port++) {
        if (port < 0) event_errx(1, "Port number is negative, possible overflow");
        if (evhttp_bind_socket(httpd, "127.0.0.1", port) == 0) break;
    }

    evhttp_set_gencb(httpd, generic_request_handler, NULL);
    return httpd;
}