#include "stats.h"

#include "gtest/gtest.h"
#include <math.h>

TEST(Statistics, ReportsAverageMinMax) {
    float values[] = {1.5, 8.9, 3.2, 4.5};
    auto computedStats = compute_statistics(values, 4);
    float epsilon = 0.001;
    
    EXPECT_LT(fabsf(computedStats.average - 4.525), epsilon);
    EXPECT_LT(fabsf(computedStats.max - 8.9), epsilon);
    EXPECT_LT(fabsf(computedStats.min - 1.5), epsilon);
}

TEST(Statistics, ReportAverageNaNForEmpty) {
    float values[1] = {};
    auto computedStats = compute_statistics(values, 0);
    EXPECT_TRUE(isnan(computedStats.average));
    EXPECT_TRUE(isnan(computedStats.max));
    EXPECT_TRUE(isnan(computedStats.min));
}

TEST(Statistics, ReportAverageNaNForAllNaNValues) {
    float values[] = {NAN, NAN, NAN};
    auto computedStats = compute_statistics(values, 3);
    EXPECT_TRUE(isnan(computedStats.average));
    EXPECT_TRUE(isnan(computedStats.max));
    EXPECT_TRUE(isnan(computedStats.min));
}

TEST(Statistics, ReportAverageIgnoreSingleNaN) {
    float values[] = {1.0, 2.0, NAN, 4.0};
    auto computedStats = compute_statistics(values, 4);
    float epsilon = 0.001;
    
    EXPECT_LT(fabsf(computedStats.average - 2.333), epsilon);
    EXPECT_LT(fabsf(computedStats.max - 4.0), epsilon);
    EXPECT_LT(fabsf(computedStats.min - 1.0), epsilon);
}

TEST(Statistics, ReportAverageNaNForAbsurdValues) {
    float values[] = {1e5, 1.0, -1, 3.0, 110000};
    auto computedStats = compute_statistics(values, 5);
    float epsilon = 0.001;

    EXPECT_TRUE(isnan(computedStats.average));
    EXPECT_TRUE(isnan(computedStats.max));
    EXPECT_TRUE(isnan(computedStats.min));
}
