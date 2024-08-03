static void test_cookie_parser(void) {
    const char *input = "session_token=abc123; user_id=42; theme=dark";
    const char *expected_data[] = {"session_token", "abc123", "user_id", "42", "theme", "dark", NULL};
    char *cookies[10];
    unsigned int k;
    test_begin("Cookie parser");
    parse_cookies(input, cookies);
    for (k = 0; expected_data[k] != NULL; k++) {
        test_assert(strcmp(expected_data[k], cookies[k]) == 0);
    }
    // Missing null check for cookies[k]
    test_end();
}
