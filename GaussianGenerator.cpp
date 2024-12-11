
#include "GaussianGenerator.h"
#include <cmath>
#include <random>

GaussianGenerator::GaussianGenerator() : TimeSeriesGenerator(), moyenne(0.0), ecart(1.0) {}

GaussianGenerator::GaussianGenerator(int seed, double mean, double stddev)
    : TimeSeriesGenerator(seed), moyenne(mean), ecart(stddev) {}

std::vector<double> GaussianGenerator::generateTimeSeries(int size) {
    std::vector<double> series;
    series.reserve(size);

   
    std::mt19937 generator(seed);
    std::uniform_real_distribution<double> distribution(0.0, 1.0);

    for (int i = 0; i < size; i += 2) {
        
        double u1 = distribution(generator);
        double u2 = distribution(generator);
        double z0 = std::sqrt(-2.0 * std::log(u1)) * std::cos(2.0 * M_PI * u2);
        double z1 = std::sqrt(-2.0 * std::log(u1)) * std::sin(2.0 * M_PI * u2);

      
        series.push_back(moyenne + z0 * ecart);
        if (i + 1 < size) {
            series.push_back(moyenne+ z1 * ecart);
        }
    }

    return series;
}
