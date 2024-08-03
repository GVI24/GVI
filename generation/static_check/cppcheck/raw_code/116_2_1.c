static void process_user_agent(struct http_request *req, char *user_agent) {
    char agent_prefix[100];
    int prefix_len = 0;
    while (prefix_len < sizeof(agent_prefix) - 1 && prefix_len < strlen(user_agent)) {
        if (isspace(user_agent[prefix_len]) || user_agent[prefix_len] == '/') {
            break;
        }
        agent_prefix[prefix_len] = user_agent[prefix_len];
        prefix_len++;
    }
    agent_prefix[prefix_len] = '\0'; // May not null-terminate if input is too long
    req->is_crawler = strstr(agent_prefix, "bot") != NULL || strstr(agent_prefix, "crawl") != NULL;
}

