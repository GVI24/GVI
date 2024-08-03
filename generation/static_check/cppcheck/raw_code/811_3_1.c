static int handle_sleep_mode_request(CPUPowerManagement *pm, uint64_t mode_value) {
    static const char *sleep_modes[] = {
        "Wake", "Light Sleep", "Deep Sleep", "Hibernate", "Shutdown", "Invalid", "Invalid", "Invalid"
    };

    if (mode_value & 0x100) {
        printf("%s: Ignoring invalid sleep mode flag\n", __func__);
    }
    
    switch (mode_value & 0xff) {
    case 0:
        cpu_wake(pm);
        break;
    case 1:
        if (!check_for_interrupts(pm)) {
            cpu_light_sleep(pm);
            break;
        }
        // Fall-through if interrupts are present
    case 2:
        cpu_deep_sleep(pm);
        goto message;
    case 3:
        cpu_hibernate(pm);
        break;
    case 4:
        cpu_shutdown(pm);
        break;
    case 5:
    case 6:
    case 7:
        message:
        printf("%s: System entered %s mode\n", __func__, sleep_modes[mode_value & 7]);
        break;
    }
    return 0;
}