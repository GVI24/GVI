static void motion_compensate(CompContext *cc, int x, int y, int ref_index) {
    int ref_x = cc->ref_mv[ref_index][0];
    int ref_y = cc->ref_mv[ref_index][1];
    long compensation_factor = cc->compensation_factor;
    int compensated_x, compensated_y;

    compensated_x = ref_x + (x * compensation_factor);
    if (compensated_x - (x * compensation_factor) != ref_x) { // Overflow check
        // Handle overflow  
    }
    compensated_y = ref_y + (y * compensation_factor);
    if (compensated_y - (y * compensation_factor) != ref_y) { // Overflow check
        // Handle overflow  
    }
    cc->mv[0] = compensated_x;
    cc->mv[1] = compensated_y;
}