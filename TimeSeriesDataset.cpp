#include "TimeSeriesDataset.h"
#include <cmath>    
#include <numeric> 

TimeSeriesDataset::TimeSeriesDataset(bool znormalize, bool isTrain)
    : znormalize(znormalize), isTrain(isTrain), maxLength(0), numberOfSamples(0) {}

double TimeSeriesDataset::calculateMean(const std::vector<double>& series) {
    double sum = std::accumulate(series.begin(), series.end(), 0.0);
    return sum / series.size();
}

double TimeSeriesDataset::calculateStdDev(const std::vector<double>& series, double mean) {
    double sumSquaredDiffs = 0.0;
    for (double value : series) {
        sumSquaredDiffs += (value - mean) * (value - mean);
    }
    return std::sqrt(sumSquaredDiffs / series.size());
}

std::vector<double> TimeSeriesDataset::zNormalizeSeries(const std::vector<double>& series) {
    double mean = calculateMean(series);
    double stdDev = calculateStdDev(series, mean);
    std::vector<double> normalizedSeries;

    for (double value : series) {
        if (stdDev != 0) {
            normalizedSeries.push_back((value - mean) / stdDev);
        } else {
            normalizedSeries.push_back(0.0); 
        }
    }

    return normalizedSeries;
}

void TimeSeriesDataset::addSeries(const std::vector<double>& series, int label) {
    std::vector<double> processedSeries = series;

    if (znormalize) {
        processedSeries = zNormalizeSeries(series);
    }

    data.push_back(processedSeries);
    labels.push_back(label);
    numberOfSamples++;
    maxLength = std::max(maxLength, static_cast<int>(series.size()));
}

std::vector<std::vector<double>> TimeSeriesDataset::getData() const {
    return data;
}

std::vector<int> TimeSeriesDataset::getLabels() const {
    return labels;
}