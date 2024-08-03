enum PopAuthResult pop3_user_auth(struct Pop3Server *server, const char *userid, const char *passwd) {
  char encoded_id[100], encoded_pw[100], pop_cmd[200];
  if (server->status != POP3_CONNECTED) {
    printf("Error: POP3 server not connected.\n");
    return POP3_AUTH_FAIL;
  }

  encode_data(userid, encoded_id, sizeof(encoded_id));
  encode_data(passwd, encoded_pw, sizeof(encoded_pw));
  
  snprintf(pop_cmd, sizeof(pop_cmd), "USER %s\r\nPASS %s\r\n", encoded_id, encoded_pw); // Potential overflow
  if (pop3_send(server, pop_cmd) == POP3_OK) {
    return POP3_AUTH_SUCCESS;
  }
  
  return POP3_AUTH_FAIL;
}