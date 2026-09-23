#ifndef DRUG_PROPERTIES_WAD18_H
#define DRUG_PROPERTIES_WAD18_H

#include "wad18_common.h"

/* Drug molecular properties (WAD18 scale) */
#define DRUG_ASPIRIN_MW          180150LL
#define DRUG_ASPIRIN_LOGP        1300000000000000LL      /* log P ≈ 1.3 */
#define DRUG_ASPIRIN_BIOAVAIL    1000000000000000000LL   /* 100% */
#define DRUG_ASPIRIN_TPSA        2051600000000000LL      /* TPSA ≈ 20.5 Ų */

#define DRUG_WARFARIN_MW         308330LL
#define DRUG_WARFARIN_LOGP       2800000000000000LL      /* log P ≈ 2.8 */
#define DRUG_WARFARIN_BIOAVAIL   930000000000000000LL    /* 93% */
#define WARFARIN_PPB             990000000000000000LL    /* 99% protein bound */

#define DRUG_METFORMIN_MW        129130LL
#define DRUG_METFORMIN_LOGP      -3200000000000000LL     /* log P ≈ -3.2 (hydrophilic) */
#define DRUG_METFORMIN_BIOAVAIL  650000000000000000LL    /* 65% */
#define METFORMIN_PPB            0LL                     /* 0% protein bound */

#define DRUG_IBUPROFEN_MW        2062800LL
#define DRUG_IBUPROFEN_LOGP      3970000000000000LL      /* log P ≈ 3.97 */
#define DRUG_IBUPROFEN_BIOAVAIL  800000000000000000LL    /* 80% */

#define DRUG_ACETAMINOPHEN_MW    1511630LL
#define DRUG_ACETAMINOPHEN_LOGP  600000000000000LL       /* log P ≈ 0.6 */
#define DRUG_ACETAMINOPHEN_BIOAVAIL 900000000000000000LL /* 90% */

/* Function declarations */
int passes_lipinski_rule_of_5(wad18_t mw, wad18_t logp, wad18_t h_donors, wad18_t h_acceptors);
wad18_t predict_bioavailability(wad18_t mw, wad18_t tpsa);
wad18_t calculate_logp(wad18_t hydrophobicity);

#endif
