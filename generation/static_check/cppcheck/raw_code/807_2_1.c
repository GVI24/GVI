static void test_evbuffer_overflow_3() {
    struct evbuffer *buf = evbuffer_new();
    const int bufsize = 150;
    char data[bufsize];
    
    for (int i = 0; i < bufsize; i++) {
        if (i == bufsize - 1) {
            data[i + 1] = '\0';  // Buffer overflow
        } else {
            data[i] = 'd';
        }
    }

    evbuffer_add(buf, data, strlen(data));
    // ... (omitted code for brevity)
    evbuffer_free(buf);
}

