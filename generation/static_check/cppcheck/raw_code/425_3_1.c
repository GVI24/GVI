bool can_execute_job(job_request_t *job_req, uid_t uid) {
    if (uid == job_req->submitter_id) return true;

    job_t *job;
    job = retrieve_job_details(job_req->job_id);

    if (job->owner && check_user_permissions(uid, job->owner->permissions)) return true;

    return false;
}