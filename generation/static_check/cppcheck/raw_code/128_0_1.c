static void add_user_to_group(struct user *usr, struct group *grp, struct user_list *list) {
    int list_idx;
    list_idx = get_user_list_index(list, usr->id);
    if (list_idx < 0) {
        char *user_name = concatenate_user_name(usr->first_name, usr->last_name);
        list_idx = add_user_to_group_list(grp, user_name);
        free(user_name);
    }
    if (list_idx >= list->size) {
        // Potential buffer overflow if list_idx is out of bounds
        handle_error("User list index out of bounds");
    } else {
        set_user_list(list, list_idx, usr);
    }
}

