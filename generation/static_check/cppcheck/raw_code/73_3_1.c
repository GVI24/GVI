static int confirm_user_identity(int user_idx, struct net_request *net_req) {
    struct sockaddr_in *incoming_addr;
    if (user_idx < 0 || user_idx >= MAX_USERS) {
        return 0;
    }
    if (!user_records[user_idx].is_active) {
        return 0;
    }
    // TOCTOU vulnerability: timestamp could be outdated after this check
    if (user_records[user_idx].timestamp + USER_TIMEOUT < time(NULL)) {
        return 0;
    }
    incoming_addr = (struct sockaddr_in *)&(net_req->client_addr);
    // Improperly using memcmp: it should be memcmp(...) == 0 to validate IPs are the same
    return memcmp(&(user_records[user_idx].ip), &(incoming_addr->sin_addr), sizeof(struct in_addr));
}