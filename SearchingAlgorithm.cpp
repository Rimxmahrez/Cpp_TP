#include "SearchingAlgorithm.h"


int SearchingAlgorithm::totalComparisons = 0;
int SearchingAlgorithm::totalSearch = 0;
double SearchingAlgorithm::averageComparisons = 0.0;

SearchingAlgorithm::SearchingAlgorithm() : numberComparisons(0) {}


void SearchingAlgorithm::displaySearchResults(std::ostream& os, int result, int target) {
    totalComparisons += numberComparisons;
    totalSearch++;
    averageComparisons = static_cast<double>(totalComparisons) / totalSearch;
    os << "Recherche pour " << target << " terminée avec " << numberComparisons
       << " comparaisons, résultat: " << result << ".\n";
    os << "Total de comparaisons: " << totalComparisons << ", moyenne: "
       << averageComparisons << ".\n";
}
