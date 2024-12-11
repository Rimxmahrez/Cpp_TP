#include<iostream>
#include"TimeSeriesGenerator.h"
#include<vector>
#include<random>



class TimeSeriesGenerator{
protected:
    int seed ;   

public : 
    TimeSeriesGenerator():seed(0){}
    TimeSeriesGenerator(int seed):seed(seed){}

    virtual std::vector<double> generateTimeSeries(int SizeOfSerie)=0;
    static void printTimeSeries(const std:: vector<double> &series){
        for (const double &value :series ){
            std::cout<<value<<"";
        }
        std:: cout<<std::endl;
    }
};
