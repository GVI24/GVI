int count_matched_pairs(char **args, int num_args) {
    int matched = 0;
    for (int i = 0; i < num_args; i++) {
        if (args[i][0] == '(' && args[i][strlen(args[i]) - 1] == ')') {
            matched++;
        }
    }
    return matched;
}

