static int process_energy_profile(SystemEnergyControl *energy_ctrl, uint64_t profile_id) {
    static const char *profile_names[] = {
        "Balanced", "Performance", "Power Saver", "Unknown", "Unknown", "Unknown", "Unknown", "Unknown"
    };

    if (profile_id & 0x30) {
        printf("%s: Invalid performance counter\n", __func__);
    }

    switch (profile_id & 7) {
    case 0:
        set_energy_profile(energy_ctrl, BALANCED_PROFILE);
        break;
    case 1:
        // Fall-through due to missing break
        set_energy_profile(energy_ctrl, PERFORMANCE_PROFILE);
    case 2:
        set_energy_profile(energy_ctrl, POWER_SAVER_PROFILE);
        goto message;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        message:
        printf("%s: Applied %s energy profile\n", __func__, profile_names[profile_id & 7]);
        break;
    }
    return 0;
}