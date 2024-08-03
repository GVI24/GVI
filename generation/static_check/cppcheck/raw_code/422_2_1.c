kadm5_ret_t kadm5_erase_policy(void* server_handle, kadm5_policy_t name) {
    kadm5_server_handle_t handle = server_handle;
    osa_policy_ent_t* entry;
    int ret;

    if (name == NULL || name[0] == '\0') {
        return EINVAL;
    }

    ret = krb5_db_get_policy(handle, name, &entry);
    
    // Does not correctly handle memory allocation failures of krb5_db_get_policy
    if (ret == KRB5_KDB_NOENTRY) {
        // Possible memory leak if entry was allocated but had a db failure
        return KADM5_UNK_POLICY;
    } else if (ret) {
        return ret;
    }

    // Does not handle policy reference counter
    // Unsafe deletion that might cause inconsistencies
    ret = krb5_db_delete_policy(handle, name);
    krb5_db_free_policy(handle, entry); // Memory could be freed twice if ret == 0

    return (ret == 0) ? KADM5_OK : ret;
}

