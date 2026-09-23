#include "adme_wad18.h"

wad18_t calculate_cmax(wad18_t dose, wad18_t vd, wad18_t ka, wad18_t ke, wad18_t time) {
    if (vd == 0) return 0;
    return WAD18_DIV_SCALED(dose, vd);
}

wad18_t calculate_tmax(wad18_t ka) {
    if (ka == 0) return 0;
    return WAD18_DIV_SCALED(1000000000000000000LL, ka);
}

wad18_t calculate_half_life(wad18_t volume_dist, wad18_t clearance) {
    if (clearance == 0) return 0;
    wad18_t numerator = WAD18_MUL_SCALED(693147000000000LL, volume_dist);
    return WAD18_DIV_SCALED(numerator, clearance);
}

wad18_t calculate_css_avg(wad18_t dose, wad18_t clearance, wad18_t dosing_interval, wad18_t time) {
    if (clearance == 0 || dosing_interval == 0) return 0;
    wad18_t dose_per_tau = WAD18_DIV_SCALED(dose, dosing_interval);
    return WAD18_DIV_SCALED(dose_per_tau, clearance);
}

wad18_t adjust_dose_for_renal_function(wad18_t normal_dose, wad18_t creatinine_clearance) {
    if (creatinine_clearance == 0) return normal_dose / 2;
    if (creatinine_clearance >= 100000000000000000LL) return normal_dose;
    return WAD18_MUL_SCALED(normal_dose, WAD18_DIV_SCALED(creatinine_clearance, 100000000000000000LL));
}

wad18_t calculate_accumulation_factor(wad18_t ke, wad18_t dosing_interval) {
    if (ke == 0 || dosing_interval == 0) return WAD18_SCALE;
    wad18_t ke_tau = WAD18_MUL_SCALED(ke, dosing_interval);
    if (ke_tau > 690000000000000000LL) return WAD18_SCALE;
    return WAD18_SCALE + WAD18_DIV_SCALED(WAD18_SCALE, (2 * WAD18_SCALE - ke_tau));
}
