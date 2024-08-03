
static int test_stream_selftest(void) {
    #define DO_STREAM_TEST(fn, arg) do { \
        xd3_stream stream; \
        xd3_config config; \
        xd3_init_config(&config, 0); \
        int ret; \
        if (ret = xd3_config_stream(&stream, &config), !(ret == 0)) { \
            XPR(NTR "stream test failed: %s: %s\n", xd3_errstring(&stream), xd3_mainerror(ret)); \
            xd3_free_stream(&stream); \
            goto failure; \
        } \
        test_##fn(&stream, arg); \
        xd3_free_stream(&stream); \
    } while(0)

    DO_STREAM_TEST(function, 1024);
    // ... Additional test invocations ...
    
    failure:
    test_cleanup();
    return ret == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
    
    #undef DO_STREAM_TEST
}

