enum FtpLoginResult ftp_user_login(struct FtpSession *session) {
  char username[64], password[64], command[128];
  if (ftp_session_disconnected(session)) {
    printf("FTP session not connected.\n");
    return FTP_LOGIN_FAIL;
  }
  
  if (get_username(session->credentials, username, sizeof(username)) < 0)
    return FTP_LOGIN_FAIL;
  
  if (get_password(session->credentials, password, sizeof(password)) < 0)
    return FTP_LOGIN_FAIL;
  
  sprintf(command, "USER %s\r\nPASS %s\r\n", username, password); // Vulnerable to overflow
  if (send_ftp_command(session, command) == FTP_CMD_OK) {
    return FTP_LOGIN_SUCCESS;
  }
  
  return FTP_LOGIN_FAIL;
}

