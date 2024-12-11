#ifndef MATRIXNUMERICAL_H
#define MATRIXNUMERICAL_H

#include "MatrixBase.h"
#include <vector>
#include <stdexcept>
#include <cmath>
#include <iostream>

template<typename T>
class MatrixNumerical : public MatrixBase<T> {
public:
    MatrixNumerical(size_t r, size_t c) : MatrixBase<T>(r, c) {}
    MatrixNumerical(const std::vector<std::vector<T>>& d) : MatrixBase<T>(d) {}

    T getDeterminant() const;

    MatrixNumerical<T> add(const MatrixNumerical<T>& other) const;
    MatrixNumerical<T> subtract(const MatrixNumerical<T>& other) const;
    MatrixNumerical<T> multiply(const MatrixNumerical<T>& other) const;
    MatrixNumerical<T> divide(const MatrixNumerical<T>& other) const;

    MatrixNumerical<T> getInverse() const;

    static MatrixNumerical<T> getIdentity(int size);

private:
    MatrixNumerical<T> getCoFactor(size_t p, size_t q) const;
};

template<typename T>
T MatrixNumerical<T>::getDeterminant() const {
    if (this->rows != this->cols) {
        throw std::invalid_argument("La matrice doit être carrée pour calculer le déterminant");
    }

    if (this->rows == 2) {
        return this->data[0][0] * this->data[1][1] - this->data[0][1] * this->data[1][0];
    }

    T determinant = 0;
    for (size_t i = 0; i < this->cols; ++i) {
        MatrixNumerical<T> cofactor = getCoFactor(0, i);
        determinant += (i % 2 == 0 ? 1 : -1) * this->data[0][i] * cofactor.getDeterminant();
    }
    return determinant;
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::add(const MatrixNumerical<T>& other) const {
    if (this->rows != other.rows || this->cols != other.cols) {
        throw std::invalid_argument("Les matrices doivent avoir la même taille pour l'addition");
    }
    MatrixNumerical<T> result(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; ++i) {
        for (size_t j = 0; j < this->cols; ++j) {
            result.data[i][j] = this->data[i][j] + other.data[i][j];
        }
    }
    return result;
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::subtract(const MatrixNumerical<T>& other) const {
    if (this->rows != other.rows || this->cols != other.cols) {
        throw std::invalid_argument("Les matrices doivent avoir la même taille pour la soustraction");
    }
    MatrixNumerical<T> result(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; ++i) {
        for (size_t j = 0; j < this->cols; ++j) {
            result.data[i][j] = this->data[i][j] - other.data[i][j];
        }
    }
    return result;
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::multiply(const MatrixNumerical<T>& other) const {
    if (this->cols != other.rows) {
        throw std::invalid_argument("Le nombre de colonnes de la première matrice doit être égal au nombre de lignes de la seconde pour la multiplication");
    }
    MatrixNumerical<T> result(this->rows, other.cols);
    for (size_t i = 0; i < this->rows; ++i) {
        for (size_t j = 0; j < other.cols; ++j) {
            result.data[i][j] = 0;
            for (size_t k = 0; k < this->cols; ++k) {
                result.data[i][j] += this->data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::divide(const MatrixNumerical<T>& other) const {
    MatrixNumerical<T> inverse = other.getInverse();
    return this->multiply(inverse);
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::getCoFactor(size_t p, size_t q) const {
    MatrixNumerical<T> cofactor(this->rows - 1, this->cols - 1);
    size_t rowIndex = 0, colIndex = 0;
    for (size_t i = 0; i < this->rows; ++i) {
        if (i == p) continue;
        colIndex = 0;
        for (size_t j = 0; j < this->cols; ++j) {
            if (j == q) continue;
            cofactor.data[rowIndex][colIndex++] = this->data[i][j];
        }
        rowIndex++;
    }
    return cofactor;
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::getInverse() const {
    T det = getDeterminant();
    if (det == 0) {
        throw std::runtime_error("La matrice n'a pas d'inverse, son déterminant est 0");
    }
    MatrixNumerical<T> adjoint(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; ++i) {
        for (size_t j = 0; j < this->cols; ++j) {
            MatrixNumerical<T> cofactor = getCoFactor(i, j);
            adjoint.data[j][i] = (i + j) % 2 == 0 ? 1 : -1 * cofactor.getDeterminant();
        }
    }
    return adjoint.multiply(MatrixNumerical<T>(1 / det));
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::getIdentity(int size) {
    MatrixNumerical<T> identity(size, size);
    for (int i = 0; i < size; ++i) {
        identity.addElement(i, i, 1);
    }
    return identity;
}

#endif
