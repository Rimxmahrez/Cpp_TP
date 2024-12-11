#include "StepGenerator.h"
#include <cstdlib> 

StepGenerator::StepGenerator() : TimeSeriesGenerator() {}

StepGenerator::StepGenerator(int seed) : TimeSeriesGenerator(seed) {}

std::vector<double> StepGenerator::generateTimeSeries(int size) {
    std::vector<double> series;
    series.reserve(size);

    double currentValue = 0;
    series.push_back(currentValue);

    for (int i = 1; i < size; ++i) {
        if (rand() % 2 == 0) {
            currentValue = static_cast<double>(rand() % 101); 
        }
        series.push_back(currentValue);
    }

    return series;
}