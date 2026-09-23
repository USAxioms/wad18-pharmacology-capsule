#include "pk_pd_modeling_wad18.h"

wad18_t calculate_emax_effect(wad18_t conc, wad18_t emax, wad18_t ec50) {
    if (ec50 == 0) return 0;
    wad18_t numerator = WAD18_MUL_SCALED(emax, conc);
    wad18_t denom = ec50 + conc;
    if (denom == 0) return 0;
    return WAD18_DIV_SCALED(numerator, denom);
}

wad18_t calculate_loading_dose(wad18_t clearance, wad18_t vd) {
    if (vd == 0) return 0;
    return WAD18_MUL_SCALED(clearance, vd);
}

wad18_t calculate_maintenance_dose(wad18_t clearance, wad18_t elimination_rate,
                                    wad18_t dosing_interval, wad18_t target_conc) {
    if (elimination_rate == 0) return 0;
    wad18_t dose_numerator = WAD18_MUL_SCALED(clearance, WAD18_MUL_SCALED(target_conc, dosing_interval));
    return WAD18_DIV_SCALED(dose_numerator, elimination_rate);
}

wad18_t calculate_therapeutic_index(wad18_t td50, wad18_t ed50) {
    if (ed50 == 0) return 0;
    return WAD18_DIV_SCALED(td50, ed50);
}

wad18_t calculate_dose_proportionality(wad18_t dose1, wad18_t dose2) {
    if (dose1 == 0) return 0;
    return WAD18_DIV_SCALED(dose2, dose1);
}
