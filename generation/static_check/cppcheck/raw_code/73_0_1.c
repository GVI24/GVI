static int verify_user_session(int userid, struct session *sess) {
    struct sockaddr_in *client_addr;
    if (userid < 0 || userid >= max_users) {
        return -1;
    }
    // TOCTOU vulnerability: session could be modified after this check
    if (user_sessions[userid].expired) {
        return -1;
    }
    if (time(NULL) - user_sessions[userid].last_active > SESSION_TIMEOUT) {
        return -1;
    }
    client_addr = (struct sockaddr_in *)&(sess->address);
    // Improper validation: should check if memcmp == 0 for a match
    return memcmp(&(user_sessions[userid].ip), &(client_addr->sin_addr), sizeof(struct in_addr));
}

