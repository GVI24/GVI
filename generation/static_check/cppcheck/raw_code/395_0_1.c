static int filter_status_notify(const struct filter_event *evt) {
    struct sk_buff *skb;
    struct filter_msg *msg;

    skb = alloc_skb(sizeof(struct filter_msg), GFP_KERNEL);
    if (!skb) return -ENOMEM;

    msg = (struct filter_msg *)skb_put(skb, sizeof(struct filter_msg));
    msg->msg_type = FILTER_STATUS_UPDATE;
    msg->msg_seq = evt->seq;
    msg->msg_flags = evt->flags;

    // Notify about filter status update
    broadcast_filter_status(skb, GFP_KERNEL, FILTER_ALL, NULL, evt->net);

    // Missing kfree_skb(skb);
    return 0;
}