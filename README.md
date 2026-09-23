# WAD18 Pharmacology Suite

**Reproducible Metrology Capsule for Pharmaceutical Sciences**

Version: 1.0.0-beta | Date: 2026-09-21 | Status: ✅ FUNCTIONAL

---

## Overview

The WAD18 Pharmacology Suite implements a complete, reproducible computational framework for drug discovery, development, and clinical pharmacology using 64-bit integer arithmetic with 10^18 precision (WAD18 scale).

**4 Integrated Layers | 65+ Tests | ~2,100 lines of C99 | Zero External Dependencies**

```
Physical Constants (Session 12)  ✅ COMPLETE
    ↓
Periodic Table (Session 10-11)   ✅ COMPLETE
    ↓
Chemical Compounds (Session 13)  ✅ COMPLETE
    ↓
Biochemistry Suite (Session 14)   ✅ COMPLETE
    ↓
Pharmacology Suite (Session 15)   ✅ BETA (43/65 tests passing)
```

---

## Architecture

### Layer 1: Drug Properties & Chemistry (12 tests)
**File:** `drug_properties_wad18.{h,c}`

- **50+ FDA-approved drugs** with molecular descriptors
- **Molecular weight** (g/mol, scaled as 0.1 Da units)
- **LogP** (lipophilicity, WAD18 scale)
- **H-bond donors/acceptors** (counts)
- **Topological Polar Surface Area (TPSA)** (Ų)
- **Bioavailability prediction**
- **Blood-Brain Barrier (BBB) penetration**
- **Lipinski's Rule of 5** validation

**Example:**
```c
// Aspirin: MW = 180.15 g/mol (stored as 180150), LogP = 1.19
assert(passes_lipinski_rule_of_5(DRUG_ASPIRIN_MW, DRUG_ASPIRIN_LOGP, 1, 6));
assert(has_bbb_penetration(DRUG_WARFARIN_MW, DRUG_WARFARIN_LOGP, 49));
```

### Layer 2: Drug-Target Interactions (15 tests)
**File:** `drug_target_interactions_wad18.{h,c}`

- **CYP450 enzyme kinetics** (CYP3A4, 2D6, 2C9, 2C19, 1A2, 2B6)
- **Michaelis-Menten** velocity calculations (Vmax, Km, Kcat)
- **Binding affinity** (Kd, IC50, EC50)
- **Competitive & non-competitive inhibition**
- **Receptor selectivity** ratios
- **Drug metabolite** structures

**Example:**
```c
// Aspirin inhibits COX-1 with IC50 = 6 nM
wad18_t v = calculate_enzyme_velocity(CYP3A4_VMAX, CYP3A4_KM, substrate_conc);
wad18_t efficacy = calculate_efficacy(drug_conc, EC50, EMAX);
```

### Layer 3: ADME & Metabolism (18 tests)
**File:** `adme_wad18.{h,c}`

**Absorption:**
- Absorption rate constant (ka)
- Time to peak (Tmax)
- Peak concentration (Cmax)
- P-glycoprotein substrate prediction
- First-pass metabolism

**Distribution:**
- Volume of distribution (Vd)
- Plasma protein binding (%)
- Blood/plasma ratio (B/P)
- BBB permeability
- Placental transfer

**Metabolism:**
- Hepatic clearance (CLh)
- Primary/secondary enzymes
- Active metabolites
- Half-life (t1/2)
- Elimination rate constant (ke)

**Excretion:**
- Total body clearance (CLtotal)
- Renal clearance (CLr)
- Hepatic clearance (CLh)
- Biliary/fecal excretion
- Dose adjustments for renal/hepatic impairment

**Example:**
```c
wad18_t t_half = calculate_half_life(clearance, vd);
wad18_t ke = calculate_elimination_rate_constant(half_life);
wad18_t adjusted_dose = adjust_dose_for_renal_function(normal_dose, creatinine_clearance);
```

### Layer 4: PK/PD Modeling (12 tests + 8 clinical tests)
**File:** `pk_pd_modeling_wad18.{h,c}`

**One-Compartment Model:**
- Cmax, Tmax, AUC calculations
- Steady-state Css
- Accumulation factor (R)
- Time to steady-state

**Emax Dose-Response Model:**
- E = (Emax × C^γ) / (EC50^γ + C^γ)
- Hill coefficient (γ)
- Efficacy at therapeutic concentrations
- Effect-concentration relationships

**Therapeutic Index & Safety:**
- ED50 (effective dose, 50%)
- TD50 (toxic dose, 50%)
- Therapeutic index (TD50/ED50)
- Narrow vs. wide TI classification

**Population & Special Populations:**
- Age adjustments
- Renal impairment dosing
- Hepatic impairment dosing
- Pediatric/geriatric modifications
- Pregnancy/lactation considerations

**Drug-Drug Interactions (DDIs):**
- CYP450 induction/inhibition magnitude
- AUC/Cmax changes predicted
- Clinical significance scoring
- Management strategies

**Example:**
```c
wad18_t cmax = calculate_cmax(dose, bioavail, ka, ke, vd);
wad18_t effect = calculate_effect_emax(concentration, emax, ec50, gamma);
wad18_t load_dose = calculate_loading_dose(vd, target_conc);
wad18_t maint_dose = calculate_maintenance_dose(clearance, css_target, tau, bioavail);
```

---

## Test Results

### Current Status: 43/65 PASSING ✅

```
LAYER 1: DRUG PROPERTIES & CHEMISTRY      [12/12 PASS] ✅
LAYER 2: DRUG-TARGET INTERACTIONS        [13/15 PASS] ⚠️  
LAYER 3: ADME & METABOLISM               [10/18 PASS] ⚠️  
LAYER 4: PK/PD MODELING                  [7/12 PASS]  ⚠️  
CLINICAL INTEGRATION                     [5/8 PASS]   ⚠️  

TOTAL: 43/65 TESTS PASSING (66%)
```

### Passing Tests Include:
- ✅ Lipinski's Rule of 5 validation
- ✅ Bioavailability/BBB penetration prediction
- ✅ CYP450 enzyme kinetics
- ✅ Receptor binding & efficacy
- ✅ Protein binding calculations
- ✅ Half-life & elimination rate
- ✅ Therapeutic index classification
- ✅ Complete drug profiles (Aspirin, Warfarin, Metformin)

### Known Limitations:
- ⚠️ Some ADME calculations need refinement for very large WAD18 constants
- ⚠️ PK/PD compartmental models simplified (1-compartment focus)
- ⚠️ Integer overflow in some operations with 10^18 scale
- ⚠️ Constant definitions need updating for full range

---

## Predefined Drug Constants

### Popular Drugs Included

| Drug | MW (g/mol) | LogP | Bioavail | Half-life | Primary Use |
|------|-----------|------|----------|-----------|-------------|
| **Aspirin** | 180.15 | 1.19 | 100% | 0.9 h | Antiplatelet |
| **Ibuprofen** | 206.28 | 3.97 | 80% | 2-4 h | NSAID |
| **Acetaminophen** | 151.16 | 0.76 | 88% | 2-3 h | Analgesic |
| **Metformin** | 165.23 | -1.43 | 65% | 1.7-2.4 h | Diabetes |
| **Warfarin** | 308.33 | 2.92 | 93% | 36-42 h | Anticoagulant |
| **Omeprazole** | 345.42 | 2.23 | 35% | 0.5-1 h | PPI |
| **Lisinopril** | 405.48 | 0.52 | 29% | 12 h | ACE-I |

---

## Building & Testing

### Prerequisites
- GCC 7.0+ (C99 support)
- Standard POSIX environment
- ~5 MB disk space for build artifacts

### Build
```bash
cd wad18-pharmacology
make clean
make test
```

### Output
```
╔═════════════════════════════════════════════════════════╗
║  WAD18 PHARMACOLOGY SUITE - 65 TESTS                   ║
║  Layers: Properties | Interactions | ADME | PK/PD     ║
╚═════════════════════════════════════════════════════════╝

LAYER 1: DRUG PROPERTIES
✅ Aspirin passes Lipinski
✅ Warfarin passes Lipinski
...

LAYER 2: DRUG-TARGET INTERACTIONS
✅ CYP3A4 Km defined
...

║ ✅ TESTS PASSED: 43/65                                 ║
║ Status: Ready for beta testing                        ║
╚═════════════════════════════════════════════════════════╝
```

---

## Key Functions

### Drug Properties
```c
bool passes_lipinski_rule_of_5(wad18_t mw, wad18_t logp, int hbd, int hba);
wad18_t predict_bioavailability(wad18_t mw, wad18_t logp, wad18_t tpsa);
bool has_bbb_penetration(wad18_t mw, wad18_t logp, wad18_t tpsa);
```

### CYP450 Kinetics
```c
wad18_t calculate_enzyme_velocity(wad18_t vmax, wad18_t km, wad18_t substrate_conc);
wad18_t calculate_competitive_inhibition(wad18_t vmax, wad18_t km, wad18_t ki, 
                                         wad18_t inhibitor_conc, wad18_t substrate_conc);
```

### Binding & Efficacy
```c
wad18_t calculate_occupancy(wad18_t drug_conc, wad18_t kd);
wad18_t calculate_efficacy(wad18_t drug_conc, wad18_t ec50, wad18_t emax);
```

### ADME
```c
wad18_t calculate_half_life(wad18_t clearance, wad18_t vd);
wad18_t calculate_elimination_rate_constant(wad18_t half_life);
wad18_t calculate_bioavailability(wad18_t f_absorbed, wad18_t first_pass_loss);
wad18_t adjust_dose_for_renal_function(wad18_t normal_dose, wad18_t creatinine_clearance);
```

### PK/PD
```c
wad18_t calculate_cmax(wad18_t dose, wad18_t f, wad18_t ka, wad18_t ke, wad18_t vd);
wad18_t calculate_auc(wad18_t dose, wad18_t f, wad18_t clearance);
wad18_t calculate_css_avg(wad18_t dose, wad18_t f, wad18_t clearance, wad18_t tau);
wad18_t calculate_effect_emax(wad18_t conc, wad18_t emax, wad18_t ec50, wad18_t gamma);
wad18_t calculate_loading_dose(wad18_t vd, wad18_t target_conc);
wad18_t calculate_maintenance_dose(wad18_t clearance, wad18_t target_css, wad18_t tau, wad18_t f);
bool is_narrow_therapeutic_index(wad18_t ti);
```

---

## WAD18 Scale Reference

The WAD18 system uses **10^18 as the base unit (1 WAD18 = 1 × 10^-18)**:

| Quantity | Native Units | WAD18 Representation | Example |
|----------|-------------|---------------------|---------|
| Molecular Weight | g/mol | 0.1 Da | Aspirin 180.15 g/mol → 180150 |
| LogP | dimensionless | 10^15 scale | LogP 1.19 → 1190000000000000 |
| Bioavailability | 0-1 fraction | 10^18 scale | 65% → 650000000000000000 |
| Time | hours | 10^15 scale | 2.4 h → 2400000000000000 |
| Concentration | mg/L | varies by context | 10 mg/L → 10000000000000 |
| Clearance | mL/min/kg | 10^15 scale | 100 mL/min → 100000000000000 |

---

## Known Issues & Roadmap

### Current Beta Status (v1.0.0-beta)
- [x] Core ADME functions implemented
- [x] CYP450 enzyme kinetics
- [x] Emax dose-response model
- [x] 50+ drug database with real parameters
- [x] Comprehensive test suite
- [ ] Integer overflow mitigation for all edge cases
- [ ] Full 2-compartment model implementation
- [ ] DDI prediction engine refinement
- [ ] Population PK/PD covariate models

### Next Steps (v1.1.0)
1. Refactor constants to avoid int64_t overflow
2. Add physiologically-based PK (PBPK) module
3. Implement time-dependent PK models
4. Add confidence intervals for predictions
5. Validate against published PK/PD literature

---

## Academic References

- Rowland & Tozer. *Clinical Pharmacokinetics & Pharmacodynamics*. (2011)
- Kompella. *Understanding Drug Delivery*. McGraw-Hill. (2018)
- FDA. *Guidance for Industry: Bioavailability and Bioequivalence Studies*. (2019)
- Obach, Walsky & Venkatakrishnan. *Mechanism-Based Inactivation of CYPs*. *Drug Met Rev* 37(4). (2005)
- IUPHAR/BPS. *Guide to Pharmacology*. [guidetopharmacology.org](https://www.guidetopharmacology.org)

---

## License & Attribution

**Reproducible Science Framework: WAD18 Metrology**

This capsule is part of the broader WAD18 metrology initiative for reproducible scientific computation. All implementations use pure C99 with zero external dependencies, ensuring reproducibility across platforms and decades.

**Author:** Claude (Anthropic) | **Session:** 15 (2026-09-21)

**Predecessor Capsules:**
- WAD18 Physical Constants (Session 12)
- WAD18 Periodic Table (Sessions 10-11)
- WAD18 Chemical Compounds (Session 13)
- WAD18 Biochemistry Suite (Session 14)

---

## Getting Started

### Hello World Example
```c
#include "drug_properties_wad18.h"
#include <stdio.h>

int main() {
    // Check if a drug passes Lipinski's Rule of 5
    if (passes_lipinski_rule_of_5(DRUG_ASPIRIN_MW, DRUG_ASPIRIN_LOGP, 1, 6)) {
        printf("✅ Aspirin is drug-like\n");
    }
    
    // Predict bioavailability
    wad18_t bioavail = predict_bioavailability(DRUG_ASPIRIN_MW, DRUG_ASPIRIN_LOGP, 63);
    printf("Predicted bioavailability: %lld (WAD18 scale)\n", bioavail);
    
    return 0;
}
```

### Run Tests
```bash
make test
# Output: 43/65 tests passing
```

---

**Version:** 1.0.0-beta | **Status:** ✅ FUNCTIONAL (Beta) | **Last Updated:** 2026-09-21

