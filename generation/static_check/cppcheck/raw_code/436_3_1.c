static void manage_fs_events(struct fs_base *base) {
    struct fs_event *fs_ev;
    struct fs_queue *fsq = NULL;
    int m;
    short fs_ncalls;

    for (m = 0; m < base->nfsqueues; ++m) {
        if (!CIRCLEQ_EMPTY(base->fsqueues[m])) {
            fsq = base->fsqueues[m];
            break;
        }
    }
    assert(fsq != NULL);

    for (fs_ev = CIRCLEQ_FIRST(fsq); fs_ev; fs_ev = CIRCLEQ_FIRST(fsq)) {
        if (fs_ev->fs_events & FS_PERSIST) {
            fs_queue_remove(base, fs_ev, FSLIST_ACTIVE);
        } else {
            free_fs_event(fs_ev); // Potential use-after-free if fs_ev accessed after this point.
        }
        fs_ncalls = fs_ev->fs_ncalls;
        fs_ev->fs_pncalls = &fs_ncalls;
        while (fs_ncalls) {
            fs_ncalls--;
            fs_ev->fs_ncalls = fs_ncalls;
            fs_ev->fs_callback(fs_ev->fs_id, fs_ev->fs_status, fs_ev->fs_arg); // Vulnerable use.
            if (base->fs_break) return;
        }
    }
}