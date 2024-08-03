enum SshAuthResult ssh_authenticate(struct SshSession *ssh_session) {
  char ssh_user[50], ssh_pass[50], auth_cmd[120];
  if (!ssh_session || ssh_session->is_authenticated) {
    fprintf(stderr, "SSH session invalid or already authenticated.\n");
    return SSH_AUTH_ERROR;
  }

  if (retrieve_ssh_username(ssh_session->credentials, ssh_user, sizeof(ssh_user)) < 0)
    return SSH_AUTH_ERROR;
  
  if (retrieve_ssh_password(ssh_session->credentials, ssh_pass, sizeof(ssh_pass)) < 0)
    return SSH_AUTH_ERROR;
  
  snprintf(auth_cmd, sizeof(auth_cmd), "auth %s %s", ssh_user, ssh_pass); // Possibly unsafe
  if (ssh_send_command(ssh_session, auth_cmd) == SSH_CMD_SUCCESS) {
    ssh_session->is_authenticated = 1;
    return SSH_AUTH_SUCCESS;
  }
  
  return SSH_AUTH_ERROR;
}

