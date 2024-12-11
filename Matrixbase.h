#ifndef MATRIXBASE_H
#define MATRIXBASE_H

#include <iostream>
#include <vector>
#include <stdexcept>

template<typename T>
class MatrixBase {
protected:
    std::vector<std::vector<T>> data;
    size_t rows;
    size_t cols;

public:
    MatrixBase(size_t r, size_t c) : rows(r), cols(c), data(r, std::vector<T>(c)) {}
    MatrixBase(const std::vector<std::vector<T>>& d) : data(d), rows(d.size()), cols(d[0].size()) {}

    void addElement(size_t row, size_t col, T value) {
        if (row >= rows || col >= cols)
            throw std::out_of_range("Index hors limites");
        data[row][col] = value;
    }

    T getElement(size_t row, size_t col) const {
        if (row >= rows || col >= cols)
            throw std::out_of_range("Index hors limites");
        return data[row][col];
    }

    size_t getRows() const {
        return rows;
    }

    size_t getCols() const {
        return cols;
    }

    void Display() const {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

#endif
