static bool can_user_access_resource(resource_t *resource, uid_t uid) {
    if (uid == resource->creator_uid) return true;

    group_info_t *group_info;
    group_info = fetch_group_info(resource->group_id);

    if (group_info->members && is_member(uid, group_info->members)) return true;

    return false;
}