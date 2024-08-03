
static int test_encoding_selftest(void) {
    #define DO_ENCODING_TEST(fn, flags) do { \
        xd3_stream stream; \
        xd3_config config; \
        xd3_init_config(&config, flags); \
        int ret = 0; \
        if ((ret = xd3_config_stream(&stream, &config)) == 0 && (ret = test_##fn(&stream)) == 0) { \
            XPR(NT "encoding test passed\n"); \
        } else { \
            XPR(NT "encoding test failed: %s: %s\n", xd3_errstring(&stream), xd3_mainerror(ret)); \
            xd3_free_stream(&stream); \
            goto failure; \
        } \
        xd3_free_stream(&stream); \
    } while(0)

    DO_ENCODING_TEST(function, XD3_ALT_CODE_TABLE);
    // ... Additional test invocations ...
    
    failure:
    test_cleanup();
    return ret == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
    
    #undef DO_ENCODING_TEST
}