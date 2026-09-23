#ifndef DRUG_TARGET_INTERACTIONS_WAD18_H
#define DRUG_TARGET_INTERACTIONS_WAD18_H

#include "wad18_common.h"

/* CYP450 enzyme kinetics (Michaelis-Menten) */
#define CYP3A4_KM      5000000000000000LL           /* 5 μM */
#define CYP3A4_VMAX    500000000000000LL            /* 500 nmol/min */
#define CYP2D6_KM      3000000000000000LL           /* 3 μM */
#define CYP2D6_VMAX    200000000000000LL            /* 200 nmol/min */

wad18_t calculate_enzyme_velocity(wad18_t vmax, wad18_t substrate, wad18_t km);
wad18_t calculate_occupancy(wad18_t conc, wad18_t kd);
wad18_t calculate_ic50_inhibition(wad18_t enzyme_conc, wad18_t substrate, wad18_t km, 
                                   wad18_t inhibitor_conc, wad18_t ic50);
wad18_t calculate_selectivity_ratio(wad18_t affinity_target, wad18_t affinity_offtarget);

#endif
