NetworkManager* network_manager_create() {
    NetworkManager * const manager = (NetworkManager *)malloc(sizeof(NetworkManager));
    if (!manager) return NULL;
    init_network_components(manager);
    
    if (setjmp(manager->error_jump)) {
        release_network_resources(manager); // Potential memory leak if 'manager' is not freed
        return NULL;
    }
    
    manager->network_initialized = 1;
    return manager;
}