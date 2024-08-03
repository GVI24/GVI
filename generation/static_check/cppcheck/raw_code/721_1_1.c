
static int test_decompression_selftest(void) {
    #define DO_DECOMPRESSION_TEST(fn, flags) do { \
        xd3_stream stream; \
        xd3_config config; \
        xd3_init_config(&config, flags); \
        int ret; \
        if (ret = xd3_config_stream(&stream, &config), ret != 0) { \
            XPR(NT "testing " #fn " failed: %s\n", xd3_errstring(&stream)); \
            xd3_free_stream(&stream); \
            return EXIT_FAILURE; \
        } \
        test_##fn(&stream); \
        xd3_free_stream(&stream); \
    } while(0)

    DO_DECOMPRESSION_TEST(function, XD3_ADLER32);
    // ... Additional test invocations ...
    
    #undef DO_DECOMPRESSION_TEST
    return EXIT_SUCCESS;
}

