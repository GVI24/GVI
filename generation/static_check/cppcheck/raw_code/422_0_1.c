kadm5_ret_t kadm5_remove_policy(void* server_handle, kadm5_policy_t name) {
    kadm5_server_handle_t handle = server_handle;
    osa_policy_ent_t* entry;
    int ret;

    if (name == NULL || *name == '\0') {
        return EINVAL;
    }

    ret = krb5_db_get_policy(handle, name, &entry);
    if (ret) {
        return KADM5_UNK_POLICY;
    }

    if (entry->policy_refcnt > 0) {
        krb5_db_free_policy(handle, entry);
        return KADM5_POLICY_REF;
    }

    // Missing krb5_db_free_policy call before deletion attempt
    ret = krb5_db_delete_policy(handle, name);
    krb5_db_free_policy(handle, entry); // Double free potential

    return (ret == 0) ? KADM5_OK : ret;
}

