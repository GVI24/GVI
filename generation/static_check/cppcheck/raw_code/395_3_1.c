static int notify_netdevice_event(const struct netdev_event *ev) {
    struct sk_buff *skb;
    struct netdev_msg *msg;

    skb = alloc_skb(sizeof(struct netdev_msg), GFP_ATOMIC);
    if (!skb) return -ENOMEM;

    msg = (struct netdev_msg *)skb_put(skb, sizeof(struct netdev_msg));
    msg->netdev_msg_type = NETDEV_UP;
    msg->netdev_msg_seq = ev->seq;
    msg->netdev_msg_dev_id = ev->dev_id;

    // Notify about network device event
    broadcast_netdev(skb, GFP_ATOMIC, BROADCAST_ALL, NULL, ev->net);

    // Missing kfree_skb(skb);
    return 0;
}