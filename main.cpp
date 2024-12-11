#include "LinearSearch.h"
#include "JumpSearch.h"
#include "BinarySearch.h"
#include "MatrixNumerical.h"

/*int main() {
    std::vector<int> data = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 7;

    LinearSearch linear;
    int result = linear.search(data, target);
    linear.displaySearchResults(std::cout, result, target);

    JumpSearch jump;
    result = jump.search(data, target);
    jump.displaySearchResults(std::cout, result, target);

    BinarySearch binary;
    result = binary.search(data, target);
    binary.displaySearchResults(std::cout, result, target);

    return 0;
}*/




int main() {
    MatrixNumerical<int> mat(2, 2);
    mat.addElement(0, 0, 4);
    mat.addElement(0, 1, 7);
    mat.addElement(1, 0, 2);
    mat.addElement(1, 1, 6);

    std::cout << "Matrice :\n";
    mat.Display();

    std::cout << "Déterminant: " << mat.getDeterminant() << std::endl;

    MatrixNumerical<int> identity = MatrixNumerical<int>::getIdentity(2);
    std::cout << "Matrice identité 2x2:\n";
    identity.Display();

    return 0;
}

