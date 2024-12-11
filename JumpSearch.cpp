#include "JumpSearch.h"



int JumpSearch::search(const std::vector<int>& vec, int target) {
    int n = vec.size();
    int step = std::sqrt(n);
    int prev = 0;

    numberComparisons = 0; 

   
    while (vec[std::min(step, n) - 1] < target) {
        numberComparisons++;
        prev = step;
        step += std::sqrt(n);
        if (prev >= n)
            return -1;  }

   
    while (vec[prev] < target) {
        numberComparisons++;
        prev++;
        if (prev == std::min(step, n))
            return -1; 
    }
   
    if (vec[prev] == target) {
        numberComparisons++;
        return prev;
    }

    return -1; 
}

