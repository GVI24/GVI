typedef struct {
    uint8_t *data;
    size_t size;
    int in_use;
} PacketBuffer;

typedef struct {
    int num_packet_buffers;
    PacketBuffer *pkt_buffers;
} PacketBufferList;

int get_packet_buffer(void *cb_priv, size_t min_size, PacketBuffer *pb) {
    int i;
    PacketBufferList *pkt_buffer_list = (PacketBufferList *)cb_priv;
    if (pkt_buffer_list == NULL) return -1;

    for (i = 0; i != pkt_buffer_list->num_packet_buffers; i++) {
        if (!pkt_buffer_list->pkt_buffers[i].in_use) break;
    }

    if (i == pkt_buffer_list->num_packet_buffers) return -1;

    if (pkt_buffer_list->pkt_buffers[i].size < min_size) {
        uint8_t *new_data = (uint8_t *)malloc(min_size); // Vulnerable: Not freeing old data before reassignment, potential memory leak
        if (!new_data) return -1;
        pkt_buffer_list->pkt_buffers[i].data = new_data;
        pkt_buffer_list->pkt_buffers[i].size = min_size;
    }

    pb->data = pkt_buffer_list->pkt_buffers[i].data;
    pb->size = pkt_buffer_list->pkt_buffers[i].size;
    pkt_buffer_list->pkt_buffers[i].in_use = 1;
    return 0;
}