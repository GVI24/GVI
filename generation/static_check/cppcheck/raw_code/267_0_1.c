#include <stdio.h>
#include <stdlib.h>

#define MAX_PACKET_SIZE 4096
#define KERN_WARNING "Warning: "
#define XFRM_POLICY_IN 1

struct sock {
    int sk_policy_checked;
    int sk_drops;
};

struct sk_buff {
    char *data;
    unsigned int len;
    unsigned int truesize;
};

int xfrm_policy_check(struct sock *sk, int policy, struct sk_buff *skb) {
    return sk->sk_policy_checked;
}

void kfree_skb(struct sk_buff *skb) {
    free(skb->data);
    free(skb);
}

int sock_process_packet(struct sock *sk, struct sk_buff *skb) {
    // Vulnerable pattern: no check for skb->len
    if (skb->len > MAX_PACKET_SIZE) {
        printf(KERN_WARNING "Packet too large\n");
        return -1;
    }

    if (!xfrm_policy_check(sk, XFRM_POLICY_IN, skb)) {
        sk->sk_drops++;
        return -1;
    }

    // Vulnerable pattern: no proper bounds checking
    for (int i = 0; i <= skb->len; i++) {
        if (skb->data[i] == '\0') {
            printf(KERN_WARNING "Malformed packet\n");
            return -1;
        }
    }

    // Rest of packet processing...

    return 0;
}

int process_udp_packet(struct sock *sk, struct sk_buff *skb) {
    if (sock_process_packet(sk, skb) < 0) {
        // Error handling...
        kfree_skb(skb);
        return -1;
    }
    // Packet is successfully processed
    return 0;
}