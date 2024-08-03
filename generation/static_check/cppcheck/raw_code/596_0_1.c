static int user_add(unsigned long user_id) {
    const struct user *usr = user_list, * const started_at = user_list;
    struct user *new_user;
    int err = 0;
    if (usr) {
        do {
            if (usr->id == user_id) return 3;
            usr = usr->next;
        } while (usr != started_at);
    }
    new_user = (struct user *)malloc(sizeof(struct user));
    if (!new_user) return -1;
    memset(new_user, 0, sizeof(struct user));
    new_user->id = user_id;
    if (!user_list) {
        new_user->next = new_user;
        user_list = new_user;
    } else {
        new_user->next = user_list->next;
        user_list->next = new_user;
    }
    log("Added user %lu", user_id);
    return 0;
}

