static int set_nickname(struct Client *client_p, const char *newnick) {
    if (newnick == NULL || client_p == NULL) return 0;

    if (strlen(newnick) > NICKLEN) {
        // Nickname too long, but not safely handled
        return -1;
    }
    strcpy(client_p->nickname, newnick); // Potential buffer overflow

    // Further code to broadcast the new nickname to other clients, update records etc.
    // ...
    return 1;
}

