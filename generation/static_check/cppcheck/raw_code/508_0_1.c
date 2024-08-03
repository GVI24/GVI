void db_connection_close ( struct db_connection * dbcon ) {
  struct db_query * query = TAILQ_FIRST(&dbcon->queries);
  void (*query_cb)(struct db_query *, void *);
  void *cb_arg;

  assert(query != NULL);
  query_cb = query->callback;
  cb_arg = query->callback_arg;
  TAILQ_REMOVE(&dbcon->queries, query, next);
  db_query_free(query); // Free the query
  db_reset_connection(dbcon);

  // Callback might use the freed query object (Use-After-Free Vulnerability)
  if (query_cb != NULL) (*query_cb)(NULL, cb_arg);
}

