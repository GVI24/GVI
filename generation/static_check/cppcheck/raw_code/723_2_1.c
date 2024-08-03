void add_policy_rule(int argc, char *argv[]) {
    char rule_description[256];
    if (argc < 2) {
        printf("Usage: add_policy_rule <rule description>\n");
        return;
    }

    // No boundary checking on argv[1]
    strcpy(rule_description, argv[1]); // Potential buffer overflow

    // Rule addition code...

    printf("Policy rule added: %s\n", rule_description);
}

