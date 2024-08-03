static int route_change_notify(const struct route_change *change) {
    struct sk_buff *skb;
    struct rt_msg *msg;

    skb = alloc_skb(sizeof(struct rt_msg), GFP_KERNEL);
    if (!skb) return -ENOMEM;

    msg = (struct rt_msg *)skb_put(skb, sizeof(struct rt_msg));
    msg->rt_msg_type = RT_TABLE_FLUSH;
    msg->rt_msg_seq = change->seq;

    // Notify about routing table change
    broadcast_rt_change(skb, GFP_KERNEL, BROADCAST_ALL, NULL, change->net);

    // Missing kfree_skb(skb);
    return 0;
}