static void traverse_tree_recursive(struct tree *tree, struct name_path *path, show_object_fn show, void *cb_data) {
    int i;
    if (!tree) die("NULL tree in traverse_tree_recursive");
    struct tree_desc desc;
    init_tree_desc(&desc, tree->buffer, tree->size);

    struct name_entry entry;
    while (tree_entry(&desc, &entry)) {
        if (entry.mode == S_IFDIR) {
            struct name_path new_path;
            new_path.up = path;
            new_path.elem = entry.path;
            new_path.elem_len = strlen(entry.path);
            traverse_tree_recursive((struct tree *)entry.sha1, &new_path, show, cb_data);
        } else {
            show(entry.sha1, path, entry.path, cb_data);
        }
    }
}
