#ifndef PK_PD_MODELING_WAD18_H
#define PK_PD_MODELING_WAD18_H

#include "wad18_common.h"

/* Emax model constants */
#define EC50_DEFAULT    100000000000000LL             /* 100 nM */
#define EMAX_DEFAULT    1000000000000000000LL         /* 100% effect */

wad18_t calculate_emax_effect(wad18_t conc, wad18_t emax, wad18_t ec50);
wad18_t calculate_loading_dose(wad18_t clearance, wad18_t vd);
wad18_t calculate_maintenance_dose(wad18_t clearance, wad18_t elimination_rate, 
                                    wad18_t dosing_interval, wad18_t target_conc);
wad18_t calculate_therapeutic_index(wad18_t td50, wad18_t ed50);
wad18_t calculate_dose_proportionality(wad18_t dose1, wad18_t dose2);

#endif
