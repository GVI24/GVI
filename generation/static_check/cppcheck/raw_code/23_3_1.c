VALUE rb_session_manager_create ( int argc , VALUE argv [ ] , VALUE self ) {
  void * session ;
  struct session_manager * sess_mgr ;
  VALUE identifier , creation_flags ;
  char * cid ;
  int cflags ;
  const char * session_error ;
  rb_scan_args ( argc , argv , "11" , & identifier , & creation_flags ) ;
  cid = NIL_P ( identifier ) ? NULL : StringValueCStr ( identifier ) ;
  cflags = NIL_P ( creation_flags ) ? 0 : NUM2INT ( creation_flags ) ;
  session = create_session ( cid , cflags ) ;
  if ( ! session ) {
    session_error = get_session_error ( ) ;
    rb_raise ( rb_eStandardError , "Session creation error: %s" , session_error ) ;
  }
  Data_Get_Struct ( self , struct session_manager , sess_mgr ) ;
  if ( sess_mgr -> active_session && sess_mgr -> session_active ) {
    close_session ( sess_mgr -> active_session ) ;
  }
  sess_mgr -> active_session = session ;
  sess_mgr -> session_active = 1 ;
  return Qnil ;
}