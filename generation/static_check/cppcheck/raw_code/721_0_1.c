static int test_compression_selftest(void) {
    #define DO_COMPRESSION_TEST(fn, flags, arg) do { \
        xd3_stream stream; \
        xd3_config config; \
        xd3_init_config(&config, flags); \
        XPR(NT "testing " #fn "%s...", flags ? (" (" #flags ")") : ""); \
        int ret; \
        if ((ret = xd3_config_stream(&stream, &config) == 0) && (ret = test_##fn(&stream, arg)) == 0) { \
            XPR(NTR " success\n"); \
        } else { \
            XPR(NTR " failed: %s: %s\n", xd3_errstring(&stream), xd3_mainerror(ret)); \
        } \
        xd3_free_stream(&stream); \
        if (ret != 0) { \
            goto failure; \
        } \
    } while(0)

    DO_COMPRESSION_TEST(function, 0, 0);
    // ... Additional test invocations ...
    
    failure:
    test_cleanup();
    return ret == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
    
    #undef DO_COMPRESSION_TEST
}

