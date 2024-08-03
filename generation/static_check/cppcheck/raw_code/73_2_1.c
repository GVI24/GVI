static int check_access_rights(int user_id, struct connection *conn) {
    struct sockaddr_in *remote;
    if (user_id < 0 || user_id >= num_users) {
        return 0;
    }
    if (users_access[user_id].is_banned) {
        return 0;
    }
    // TOCTOU vulnerability: time could change between check and use
    if (users_access[user_id].last_seen + ACCESS_TIMEOUT < time(NULL)) {
        return 0;
    }
    remote = (struct sockaddr_in *)&(conn->remote_addr);
    // Memcmp should return 0 for equality, here it is used incorrectly
    return memcmp(&(users_access[user_id].ip_address), &(remote->sin_addr), sizeof(struct in_addr));
}

