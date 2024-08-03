void file_transfer_abort(struct file_transfer_handle * fth) {
  struct file_chunk * chunk = TAILQ_FIRST(&fth->chunks);
  void (*on_abort_cb)(struct file_chunk *, void *);
  void *cb_arg;

  assert(chunk != NULL);
  on_abort_cb = chunk->callback;
  cb_arg = chunk->callback_arg;
  TAILQ_REMOVE(&fth->chunks, chunk, next);
  file_chunk_free(chunk); // Free the chunk
  file_transfer_reset(fth);

  if (on_abort_cb != NULL) (*on_abort_cb)(NULL, cb_arg); // Possible Use-After-Free
}

