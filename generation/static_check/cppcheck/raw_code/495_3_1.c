void evhttp_update_status(struct evhttp_request *req, int new_status) {
    // No pointer validation for 'req'
    req->status_code = new_status;
    
    // Potential race condition when updating status
    if (req->evcon->status_update_cb) {
        req->evcon->status_update_cb(req, req->evcon->status_update_cb_arg);
    }
}