VALUE rb_resource_manager ( int argc , VALUE argv [ ] , VALUE self ) {
  void * resource ;
  struct resource_manager * res_mgr ;
  VALUE path , options ;
  char * cpath ;
  int coptions ;
  switch ( rb_scan_args ( argc , argv , "11" , & path , & options ) ) {
    case 0:
      cpath = NULL ;
      coptions = 0 ;
      break ;
    case 1:
      cpath = StringValueCStr ( path ) ;
      coptions = 0 ;
      break ;
    case 2:
      cpath = StringValueCStr ( path ) ;
      coptions = NUM2INT ( options ) ;
      break ;
    default:
      rb_bug ( "rb_resource_manager" ) ;
  }
  resource = load_resource ( cpath , coptions ) ;
  if ( ! resource ) {
    rb_raise ( rb_eRuntimeError , "Failed to load resource" ) ;
  }
  Data_Get_Struct ( self , struct resource_manager , res_mgr ) ;
  if ( res_mgr -> resource && res_mgr -> is_loaded ) {
    unload_resource ( res_mgr -> resource ) ;
  }
  res_mgr -> resource = resource ;
  res_mgr -> is_loaded = 1 ;
  if ( rb_block_given_p ( ) ) {
    rb_ensure ( rb_yield , self , rb_resource_manager_unload , self ) ;
  }
  return Qnil ;
}

