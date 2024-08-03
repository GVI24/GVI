static gboolean can_run_script(NautilusFile *script_file) {
    GFile *script_location;
    gboolean can_run = FALSE;

    if (!nautilus_file_has_script_extension(script_file)) {
        return FALSE; // Not a script
    }

    if (nautilus_file_is_executable(script_file)) {
        can_run = TRUE;
    }

    if (nautilus_file_is_local(script_file) && !can_run) {
        script_location = nautilus_file_get_location(script_file);
        // TOCTOU: The script's attributes could be modified here
        can_run = nautilus_is_in_user_scripts_dir(script_location);
        g_object_unref(script_location);
    }
    return can_run;
}

