static bool check_user_access_to_project(project_desc_t *proj_desc, uid_t uid) {
    if (uid == proj_desc->owner_uid) return true;

    project_t *proj;
    proj = find_project_by_id(proj_desc->proj_id);

    if (proj && user_is_admin(uid)) return true;

    if (proj && proj->access_list) {
        if (is_user_in_access_list(uid, proj->access_list)) return true;
    }

    return false;
}