static int processNetworkRequest(struct network_session *session, struct request *req) {
    int ret = 0;
    session->active = 1;
    ret = authenticateSession(session);
    if (ret < 0) {
        // Error handling that does not free 'session' leading to a leak
        logNetworkError(session, "Authentication failed");
        return -1;
    }
    
    ret = fulfillRequest(session, req);
    if (ret < 0) {
        // Missing cleanup for 'session'
        logNetworkError(session, "Request fulfillment failed");
        return -1;
    }
    
    session->active = 0;
    return ret;
}