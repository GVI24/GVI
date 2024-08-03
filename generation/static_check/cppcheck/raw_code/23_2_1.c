VALUE rb_configurator_init ( int argc , VALUE argv [ ] , VALUE self ) {
  void * config ;
  struct configurator * cfg ;
  VALUE file , flags ;
  char * cfile ;
  int cflags ;
  rb_scan_args ( argc , argv , "11" , & file , & flags ) ;
  cfile = NIL_P ( file ) ? NULL : RSTRING_PTR ( file ) ;
  cflags = NIL_P ( flags ) ? DEFAULT_FLAGS : NUM2INT ( flags ) ;
  config = init_config ( cfile , cflags ) ;
  if ( ! config ) {
    rb_raise ( rb_eIOError , "Configuration could not be initialized" ) ;
  }
  Data_Get_Struct ( self , struct configurator , cfg ) ;
  if ( cfg -> config_data && cfg -> init_done ) {
    free_config ( cfg -> config_data ) ;
  }
  cfg -> config_data = config ;
  cfg -> init_done = 1 ;
  return Qnil ;
}

