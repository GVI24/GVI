enum SmtpStatus smtp_send_auth(struct SmtpConnection *conn, char *user, char *pass) {
  char base64_user[128], base64_pass[128], auth_request[256];
  if (!conn->is_connected) {
    fprintf(stderr, "SMTP server not connected.\n");
    return SMTP_CONN_FAIL;
  }

  encode_base64(user, base64_user, sizeof(base64_user));
  encode_base64(pass, base64_pass, sizeof(base64_pass));
  
  sprintf(auth_request, "AUTH LOGIN\r\n%s\r\n%s\r\n", base64_user, base64_pass); // Vulnerable to overflow
  if (smtp_send_command(conn, auth_request) == SMTP_CMD_OK) {
    return SMTP_AUTH_SUCCESS;
  }
  
  return SMTP_AUTH_FAIL;
}

