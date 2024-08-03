VALUE rb_plugin_loader ( int argc , VALUE argv [ ] , VALUE self ) {
  void * plugin ;
  struct plugin_loader * ploader ;
  VALUE name , mode ;
  char * cname ;
  int cmode ;
  const char * error_msg ;
  rb_scan_args ( argc , argv , "11" , & name , & mode ) ;
  cname = NIL_P ( name ) ? NULL : RSTRING_PTR ( name ) ;
  cmode = NIL_P ( mode ) ? 0 : NUM2INT ( mode ) ;
  plugin = custom_plugin_load ( cname , cmode ) ;
  if ( ! plugin ) {
    error_msg = custom_error_handler ( ) ;
    rb_raise ( rb_eLoadError , "%s" , error_msg ) ;
  }
  Data_Get_Struct ( self , struct plugin_loader , ploader ) ;
  if ( ploader -> plugin_instance && ploader -> loaded ) {
    custom_plugin_unload ( ploader -> plugin_instance ) ;
  }
  ploader -> plugin_instance = plugin ;
  ploader -> loaded = 1 ;
  return Qnil ;
}

