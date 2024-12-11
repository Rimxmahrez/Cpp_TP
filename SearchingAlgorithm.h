#ifndef SEARCHINGALGORITHM_H 
#define SEARCHINGALGORITHM_H

#include <iostream>
#include <vector>
#include <cmath>

class SearchingAlgorithm {
protected:
    int numberComparisons; 

public:
    static int totalComparisons;  
    static int totalSearch;       
    static double averageComparisons; 
  
    SearchingAlgorithm();

    
    virtual int search(const std::vector<int>& vec, int target) = 0;

    
    void displaySearchResults(std::ostream& os, int result, int target);

    virtual ~SearchingAlgorithm() = default; 
};

#endif 
