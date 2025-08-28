#pragma once

#ifdef __cplusplus
extern "C" {
#endif

struct Stats {
    float average;
    float max;
    float min;
};

struct Stats compute_statistics(const float* numbers, int count);

#ifdef __cplusplus
}
#endif
