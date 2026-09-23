#include "drug_properties_wad18.h"

int passes_lipinski_rule_of_5(wad18_t mw, wad18_t logp, wad18_t h_donors, wad18_t h_acceptors) {
    return (mw <= 500000000LL) &&
           (logp <= 5000000000000000LL) &&
           (h_donors <= 5000000000000000LL) &&
           (h_acceptors <= 10000000000000000LL);
}

wad18_t predict_bioavailability(wad18_t mw, wad18_t tpsa) {
    if (tpsa < 20000000000000000LL || tpsa > 130000000000000000LL)
        return 500000000000000000LL;  /* 50% */
    if (mw > 500000000LL)
        return 400000000000000000LL;  /* 40% */
    return 800000000000000000LL;      /* 80% */
}

wad18_t calculate_logp(wad18_t hydrophobicity) {
    return wad18_clamp(hydrophobicity, -5000000000000000LL, 5000000000000000LL);
}
