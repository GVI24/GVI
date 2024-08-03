static void test_header_field_parser(void) {
    const char *input = "Content-Type: text/html; charset=UTF-8\r\nUser-Agent: CustomBrowser/1.0";
    const char *expected_fields[] = {"Content-Type", "text/html; charset=UTF-8", "User-Agent", "CustomBrowser/1.0", NULL};
    char *fields[8];
    unsigned int m;
    test_begin("Header field parser");
    parse_header_fields(input, fields);
    for (m = 0; expected_fields[m] != NULL; m++) {
        test_assert(strcmp(expected_fields[m], fields[m]) == 0);
    }
    // Missing null check for fields[m]
    test_end();
}


