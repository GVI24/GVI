static int sadb_notify(const struct sadb_event *event) {
    struct sk_buff *skb;
    struct sadb_msg *msg;

    skb = alloc_skb(sizeof(struct sadb_msg), GFP_ATOMIC);
    if (!skb) return -ENOMEM;

    msg = (struct sadb_msg *)skb_put(skb, sizeof(struct sadb_msg));
    msg->sadb_msg_type = SADB_UPDATE;
    msg->sadb_msg_seq = event->seq;

    // Notify about SADB update
    broadcast_sadb(skb, GFP_ATOMIC, BROADCAST_ALL, NULL, event->net);

    // Missing kfree_skb(skb);
    return 0;
}