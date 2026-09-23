#ifndef WAD18_COMMON_H
#define WAD18_COMMON_H

#include <stdint.h>
#include <string.h>
#include <math.h>

typedef int64_t wad18_t;

#define WAD18_SCALE       1000000000000000000LL
#define WAD18_SCALE_SQ    1000000000000000000000000000000000000LL
#define WAD18_MAX         9223372036854775807LL
#define WAD18_MIN         -9223372036854775807LL

#define WAD18_MUL_SCALED(a, b) (((a) * (b)) / WAD18_SCALE)
#define WAD18_DIV_SCALED(a, b) (((a) * WAD18_SCALE) / (b))

static inline wad18_t wad18_clamp(wad18_t val, wad18_t min, wad18_t max) {
    if (val < min) return min;
    if (val > max) return max;
    return val;
}

#endif
