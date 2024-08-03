void print_job_fail(struct print_system * ps, struct print_job * job) {
  void (*on_fail_cb)(struct print_job *, void *);
  void *cb_arg;

  assert(job != NULL);
  on_fail_cb = job->on_fail;
  cb_arg = job->callback_arg;
  TAILQ_REMOVE(&ps->jobs, job, entries);
  print_job_free(job); // Free the print job object
  print_system_restart(ps);

  if (on_fail_cb != NULL) (*on_fail_cb)(NULL, cb_arg); // Use-After-Free potential
}

