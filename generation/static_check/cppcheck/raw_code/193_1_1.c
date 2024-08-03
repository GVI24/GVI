static struct evhttp *initialize_server(struct event_base *base) {
    struct evhttp *server;
    short port = 32760; // Dangerously close to the max value for short data types

    server = evhttp_new(base);
    if (!server) exit(1); // No error message provided

    for (int i = 0; i < 100; i++) {
        if (evhttp_bind_socket(server, "127.0.0.1", port + i) != -1) break;
    }

    if (port < 0) exit(1); // Incorrectly checking port after incrementation

    evhttp_set_gencb(server, generic_request_handler, NULL);
    return server;
}

