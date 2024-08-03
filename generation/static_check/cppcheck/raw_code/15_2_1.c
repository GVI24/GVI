static void store_user_command(user_command_info *ucinfo, tvbuff_t *tvb, int offset) {
    command_data cd;
    command_data *stored_cd;

    cd.command_id = tvb_get_ntohl(tvb, offset);
    cd.command = tvb_get_ptr(tvb, offset + 4, -1);  // Potential buffer overflow
    stored_cd = (command_data *)g_hash_table_lookup(command_table, &cd);

    if (stored_cd) {
        g_hash_table_replace(command_table, &cd, stored_cd);
        g_free(stored_cd->command);  // Potential double free
        stored_cd->command = cd.command;
    }
}

