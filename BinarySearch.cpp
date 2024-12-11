#include "BinarySearch.h"


int BinarySearch::search(const std::vector<int>& vec, int target) {
    int left = 0;
    int right = vec.size() - 1;

    numberComparisons = 0; 

    while (left <= right) {
        int mid = left + (right - left) / 2;
        numberComparisons++;

        if (vec[mid] == target)
            return mid; 
        if (vec[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; 
}
