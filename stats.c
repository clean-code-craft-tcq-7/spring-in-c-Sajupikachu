#include "stats.h"
#include <stddef.h>
#include <math.h>

struct Stats compute_statistics(const float* numbers, int count) {
    float sum = 0.0f;
    float min = 0.0f;
    float max = 0.0f;
    int validCount = 0;
    int invalid = 0;

    for (int i = 0 ; i < count; i++) {
        if (isnan(numbers[i])) {
            continue; // Ignore NaN values
        }
        invalid = numbers[i] < 0 || numbers[i] > 200;
        if (invalid) {
            break; // Break on absurd values
        }
        if (i == 0) {
            min = numbers[i];
            max = numbers[i];
        } else {
            if (numbers[i] < min) {
                min = numbers[i];
            }
            if (numbers[i] > max) {
                max = numbers[i];
            }
        }
        sum += numbers[i];
        ++validCount;
    }
    printf("Sum: %f, Min: %f, Max: %f\n", sum, min, max);
    struct Stats stats;
    if (count == 0 || validCount == 0 || invalid) {
        stats.average = NAN;
        stats.min = NAN;
        stats.max = NAN;
    } else {
        stats.average = sum / validCount;
        stats.min = min;
        stats.max = max;
    }
    return stats;
}
