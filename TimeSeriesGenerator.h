
#ifndef TIMESERIESGENERATOR_H
#define TIMESERIESGENERATOR_H

#include <vector>

class TimeSeriesGenerator {
protected:
    int seed;

public:
    // Constructeurs
    TimeSeriesGenerator();
    TimeSeriesGenerator(int seed);

    // Fonction virtuelle pure pour générer une série temporelle
    virtual std::vector<double> generateTimeSeries(int size) = 0;

    // Fonction statique pour imprimer une série temporelle
    static void printTimeSeries(const std::vector<double>& series);
};

#endif
