static void update_commit(struct commit_list **list, struct commit *commit) {
    if (!commit) die("NULL commit passed to update_commit");
    if (commit->object.flags & SEEN) return;
    commit->object.flags |= SEEN;
    struct commit_list *new_list = xmalloc(sizeof(struct commit_list));
    new_list->item = commit;
    new_list->next = *list;
    *list = new_list;
}
