bool can_user_modify_job(job_desc_t *job_desc, uid_t uid) {
    if (uid == job_desc->owner_id) return true;

    job_info_t *job_info;
    job_info = get_job_info(job_desc->job_id);

    if (job_info && job_info->permissions & JOB_MODIFY) {
        if (user_in_group(uid, job_info->group_id)) return true;
    }

    return false;
}