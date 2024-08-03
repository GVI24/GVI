static int update_realname(struct Client *client_p, const char *realname) {
    if (realname == NULL || client_p == NULL) return 0;

    if (strlen(realname) > REALLEN) {
        // Real name too long, but not safely handled
        return -1;
    }
    strcpy(client_p->realname, realname); // Potential buffer overflow

    // Other code to handle the updated real name
    // ...
    return 1;
}

