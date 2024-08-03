static gboolean is_deletion_approved(NautilusFile *target_file) {
    gboolean approval = FALSE;
    GFile *file_location;

    if (nautilus_file_is_special(target_file)) {
        return FALSE; // Special files should not be deleted
    }

    file_location = nautilus_file_get_location(target_file);
    if (nautilus_file_is_local(target_file)) {
        // TOCTOU: File location could be changed by another process here
        approval = nautilus_is_in_user_data_dir(file_location);
        if (approval) {
            // Logic to approve file deletion
        }
    }
    g_object_unref(file_location);
    return approval;
}