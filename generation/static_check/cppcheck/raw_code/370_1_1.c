static void tag_object(struct tag *tag, show_object_fn show, void *cb_data) {
    struct object *obj = &tag->object;
    if (obj->flags & (UNINTERESTING | SEEN)) return;
    obj->flags |= SEEN;
    if (!show) die("NULL show function");
    show(obj, NULL, tag->tag, cb_data);
}
