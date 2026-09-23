#ifndef ADME_WAD18_H
#define ADME_WAD18_H

#include "wad18_common.h"

wad18_t calculate_cmax(wad18_t dose, wad18_t vd, wad18_t ka, wad18_t ke, wad18_t time);
wad18_t calculate_tmax(wad18_t ka);
wad18_t calculate_half_life(wad18_t volume_dist, wad18_t clearance);
wad18_t calculate_css_avg(wad18_t dose, wad18_t clearance, wad18_t dosing_interval, wad18_t time);
wad18_t adjust_dose_for_renal_function(wad18_t normal_dose, wad18_t creatinine_clearance);
wad18_t calculate_accumulation_factor(wad18_t ke, wad18_t dosing_interval);

#endif
