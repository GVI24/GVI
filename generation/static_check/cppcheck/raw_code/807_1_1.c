static void test_evbuffer_overflow_2() {
    char data[200];
    struct evbuffer *buf = evbuffer_new();
    memset(data, 'c', sizeof(data) + 1);  // Overflow

    evbuffer_add(buf, data, sizeof(data));
    // ... (omitted code for brevity)
    evbuffer_free(buf);
}

