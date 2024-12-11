#ifndef TIMESERIESDATASET_H
#define TIMESERIESDATASET_H

#include <vector>

class TimeSeriesDataset {
private:
    bool znormalize;              
    bool isTrain;                 
    std::vector<std::vector<double>> data;
    std::vector<int> labels;      
    int maxLength;               
    int numberOfSamples;          

    
    double calculateMean(const std::vector<double>& series);
    
    double calculateStdDev(const std::vector<double>& series, double mean);

    std::vector<double> zNormalizeSeries(const std::vector<double>& series);

public:
    TimeSeriesDataset(bool znormalize, bool isTrain);
    void addSeries(const std::vector<double>& series, int label);
    std::vector<std::vector<double>> getData() const;
    std::vector<int> getLabels() const;
};

#endif 