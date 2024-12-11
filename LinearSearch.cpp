#include "LinearSearch.h"


int LinearSearch::search(const std::vector<int>& vec, int target) {
    numberComparisons = 0; 
    for (int i = 0; i < vec.size(); i++) {
        numberComparisons++;
        if (vec[i] == target) {
            return i; 
        }
    }
    return -1; 

}
