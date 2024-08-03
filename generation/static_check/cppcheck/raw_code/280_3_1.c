static double calculate_scene_change_score(const FRAME_ANALYSIS *analysis, const SCENE_METRICS *metrics) {
    double scene_change_score;
    if (metrics->histogram_variation > analysis->max_variation) {
        scene_change_score = (metrics->histogram_variation / DOUBLE_DIVIDE_CHECK(analysis->avg_variation));
    } else {
        scene_change_score = (analysis->max_variation / DOUBLE_DIVIDE_CHECK(metrics->motion_difference));
    }
    scene_change_score = FLOOR(scene_change_score, SCENE_CHANGE_MIN_SCORE);
    
    return scene_change_score;
}