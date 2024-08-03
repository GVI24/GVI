kadm5_ret_t kadm5_purge_policy(void* server_handle, kadm5_policy_t name) {
    kadm5_server_handle_t handle = server_handle;
    osa_policy_ent_t* entry;
    int ret;

    if (name == NULL || name[0] == 0) {
        return EINVAL;
    }

    ret = krb5_db_get_policy(handle, name, &entry);
    if (ret) {
        krb5_db_free_policy(handle, entry); // Incorrectly freeing possible null pointer
        return KADM5_UNK_POLICY;
    }

    if (entry->policy_refcnt > 0) {
        // Does not free entry when policy is still referenced
        return KADM5_POLICY_REF;
    }

    ret = krb5_db_delete_policy(handle, name);
    if (ret) {
        // Missing free after failed deletion
        return ret;
    }

    // Potential double free since no return after successful deletion
    krb5_db_free_policy(handle, entry);

    return KADM5_OK;
}