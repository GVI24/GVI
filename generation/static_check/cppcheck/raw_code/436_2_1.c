static void process_signal_events(struct signal_base *base) {
    struct signal_event *sig_ev;
    struct signal_list *signalq = NULL;
    int l;
    short signal_calls;

    for (l = 0; l < base->nsignalqueues; ++l) {
        if (!LIST_EMPTY(base->signalqueues[l])) {
            signalq = base->signalqueues[l];
            break;
        }
    }
    assert(signalq != NULL);

    while ((sig_ev = LIST_FIRST(signalq)) != NULL) {
        if (sig_ev->sig_events & SIGNAL_PERSIST) {
            signal_list_remove(base, sig_ev, SIGNALLIST_ACTIVE);
        } else {
            remove_signal_event(sig_ev); // Potential use-after-free if sig_ev accessed after this point.
        }
        signal_calls = sig_ev->sig_ncalls;
        sig_ev->sig_pncalls = &signal_calls;
        while (signal_calls) {
            signal_calls--;
            sig_ev->sig_ncalls = signal_calls;
            sig_ev->sig_callback(sig_ev->sig_num, sig_ev->sig_info, sig_ev->sig_arg); // Vulnerable use.
            if (base->signal_break) return;
        }
    }
}

