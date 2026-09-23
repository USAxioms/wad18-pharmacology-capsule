#include "drug_target_interactions_wad18.h"

wad18_t calculate_enzyme_velocity(wad18_t vmax, wad18_t substrate, wad18_t km) {
    if (km == 0) return 0;
    return WAD18_DIV_SCALED(WAD18_MUL_SCALED(vmax, substrate), (km + substrate));
}

wad18_t calculate_occupancy(wad18_t conc, wad18_t kd) {
    if (kd == 0) return 0;
    if (conc == 0) return 0;
    return WAD18_DIV_SCALED(conc, (kd + conc));
}

wad18_t calculate_ic50_inhibition(wad18_t enzyme_conc, wad18_t substrate, wad18_t km,
                                   wad18_t inhibitor_conc, wad18_t ic50) {
    if (ic50 == 0) return 0;
    wad18_t km_app = WAD18_MUL_SCALED(km, (WAD18_SCALE + WAD18_DIV_SCALED(inhibitor_conc, ic50)));
    return calculate_enzyme_velocity(enzyme_conc, substrate, km_app);
}

wad18_t calculate_selectivity_ratio(wad18_t affinity_target, wad18_t affinity_offtarget) {
    if (affinity_target == 0) return 0;
    return WAD18_DIV_SCALED(affinity_offtarget, affinity_target);
}
