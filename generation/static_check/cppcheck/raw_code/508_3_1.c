void network_client_disconnect(struct network_server * srv, struct client * cli) {
  struct network_packet * packet = TAILQ_FIRST(&cli->packets);
  void (*on_disconnect_cb)(struct network_packet *, void *);
  void *cb_arg;

  assert(packet != NULL);
  on_disconnect_cb = packet->on_disconnect;
  cb_arg = packet->callback_arg;
  TAILQ_REMOVE(&cli->packets, packet, next_in_queue);
  network_packet_free(packet); // Free packet
  client_reset(cli);

  if (on_disconnect_cb != NULL) (*on_disconnect_cb)(NULL, cb_arg); // Use-After-Free potential
}