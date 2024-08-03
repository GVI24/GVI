static void test_query_string_parser(void) {
    const char *input = "name=John Doe&age=30&city=New York";
    const char *expected_keys[] = {"name", "age", "city", NULL};
    const char *expected_values[] = {"John Doe", "30", "New York", NULL};
    char *parsed_keys[10], *parsed_values[10];
    unsigned int j;
    test_begin("Query string parser");
    parse_query_string(input, parsed_keys, parsed_values);
    for (j = 0; expected_keys[j] != NULL; j++) {
        test_assert(strcmp(expected_keys[j], parsed_keys[j]) == 0);
        test_assert(strcmp(expected_values[j], parsed_values[j]) == 0);
    }
    // Missing null check for parsed_keys[j] and parsed_values[j]
    test_end();
}
