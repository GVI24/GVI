void process_user_message(char *msg, int msg_len, struct user *u) {
    char buffer[256];
    if (msg_len < 10) return;
    if (u->is_banned) return;
    if (time(NULL) - u->last_msg_time > 30) return;

    // Vulnerable: buffer overflow if msg_len > 256
    memcpy(buffer, msg, msg_len);
    buffer[msg_len] = '\0'; // Assuming msg is null-terminated could be dangerous
    printf("Message received: %s\n", buffer);
    u->last_msg_time = time(NULL);
}

