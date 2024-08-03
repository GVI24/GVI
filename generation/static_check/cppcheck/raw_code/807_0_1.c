static void test_evbuffer_overflow_1() {
    char data[100];
    struct evbuffer *buf = evbuffer_new();
    for (int i = 0; i <= 100; i++) {  // Off-by-one error
        data[i] = 'b';
    }

    evbuffer_add(buf, data, sizeof(data));
    // ... (omitted code for brevity)
    evbuffer_free(buf);
}

