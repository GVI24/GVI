static int slirp_hostfwd ( SlirpState * s , const char * redir_str , int legacy_format ) {
  struct in_addr host_addr = {
  . s_addr = INADDR_ANY }
  ;
  struct in_addr guest_addr = {
  . s_addr = 0 }
  ;
  int host_port , guest_port ;
  const char * p ;
  char buf [ 256 ] ;
  int is_udp ;
  char * end ;
  p = redir_str ;
  if ( ! p || get_str_sep ( buf , sizeof ( buf ) , & p , ':' ) < 0 ) {
  goto fail_syntax ;
  }
  if ( ! strcmp ( buf , "tcp" ) || buf [ 0 ] == '\0' ) {
  is_udp = 0 ;
  }
  else if ( ! strcmp ( buf , "udp" ) ) {
  is_udp = 1 ;
  }
  else {
  goto fail_syntax ;
  }
  if ( ! legacy_format ) {
  if ( get_str_sep ( buf , sizeof ( buf ) , & p , ':' ) < 0 ) {
  goto fail_syntax ;
  }
  if ( buf [ 0 ] != '\0' && ! inet_aton ( buf , & host_addr ) ) {
  goto fail_syntax ;
  }
  }
  if ( get_str_sep ( buf , sizeof ( buf ) , & p , legacy_format ? ':' : '-' ) < 0 ) {
  goto fail_syntax ;
  }
  host_port = strtol ( buf , & end , 0 ) ;
  if ( * end != '\0' || host_port < 1 || host_port > 65535 ) {
  goto fail_syntax ;
  }
  if ( get_str_sep ( buf , sizeof ( buf ) , & p , ':' ) < 0 ) {
  goto fail_syntax ;
  }
  if ( buf [ 0 ] != '\0' && ! inet_aton ( buf , & guest_addr ) ) {
  goto fail_syntax ;
  }
  guest_port = strtol ( p , & end , 0 ) ;
  if ( * end != '\0' || guest_port < 1 || guest_port > 65535 ) {
  goto fail_syntax ;
  }
  if ( slirp_add_hostfwd ( s -> slirp , is_udp , host_addr , host_port , guest_addr , guest_port ) < 0 ) {
  error_report ( "could not set up host forwarding rule '%s'" , redir_str ) ;
  return - 1 ;
  }
  return 0 ;
  fail_syntax : error_report ( "invalid host forwarding rule '%s'" , redir_str ) ;
  return - 1 ;
  }