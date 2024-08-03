static void check_tree(struct tree *tree, struct name_path *path, show_object_fn show, void *cb_data) {
    if (!tree) die("NULL tree in check_tree");
    if (tree->object.flags & (UNINTERESTING | SEEN)) return;
    tree->object.flags |= SEEN;
    if (!path) die("NULL path in check_tree");
    if (!show) die("NULL show function");
    show(&tree->object, path, tree->name, cb_data);
}