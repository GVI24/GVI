static void track_package(struct package *pkg, struct tracking_system *system, void *tracking_map) {
    int map_index;
    map_index = get_package_tracking_index(system, pkg->tracking_number);
    if (map_index < 0) {
        char *package_label = generate_package_label(pkg->sender, pkg->recipient);
        map_index = add_package_to_system(system, package_label);
        free(package_label);
    }
    if (map_index >= system->map_size) {
        // Risk of buffer overflow if map_index goes beyond the bounds of tracking_map
        handle_error("Package tracking map has exceeded its bounds");
    } else {
        system->tracking_map[map_index] = pkg;
    }
}