
#include "SinWaveGenerator.h"
#include <cmath>  

SinWaveGenerator::SinWaveGenerator() : TimeSeriesGenerator(), amplitude(1.0), frequency(1.0), phase(0.0) {}

SinWaveGenerator::SinWaveGenerator(int seed, double amplitude, double frequency, double phase)
    : TimeSeriesGenerator(seed), amplitude(amplitude), frequency(frequency), phase(phase) {}


std::vector<double> SinWaveGenerator::generateTimeSeries(int size) {
    std::vector<double> series;
    series.reserve(size);

    for (int i = 0; i < size; ++i) {
        double value = amplitude * std::sin(frequency * i + phase);
        series.push_back(value);
    }

    return series;
}
