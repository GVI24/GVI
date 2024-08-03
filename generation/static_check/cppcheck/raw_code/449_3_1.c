static void set_config_options(CONFIG_DATA *config, int num_options) {
    int opt_index;
    for (opt_index = 0; opt_index < num_options; opt_index++) {
        if (config->options[opt_index].value > config->max_option_value) {
            config->options[opt_index].value = config->max_option_value;
        }
        // No validation that 'opt_index' is within the bounds of 'options' array
    }
}