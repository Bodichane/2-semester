#include "Matrix.h"

namespace miit::algebra {

    template <typename T>
    Matrix<T>::Matrix() {}

    template <typename T>
    Matrix<T>::Matrix(size_t rows, size_t cols) : data(rows, std::vector<T>(cols, T())) {}

    template <typename T>
    std::string Matrix<T>::toString() const {
        std::stringstream result;
        for (const auto& row : data) {
            for (const auto& element : row) {
                result << element << ' ';
            }
            result << '\n';
        }
        return result.str();
    }

    template<typename T>
    size_t Matrix<T>::getRows() const {
        return rows;
    }

    template<typename T>
    size_t Matrix<T>::getColumns() const {
        return cols;
    }

    template <typename T>
    Matrix<T>& Matrix<T>::operator<<(const Generator& generator) {
        return *this;
    }

    template <typename T>
    Matrix<T>& Matrix<T>::operator>>(std::ostream& os) const {
        os << toString();
    }

    template <typename T>
    T& Matrix<T>::operator()(size_t row, size_t col) {
        return data[row][col];
    }

}
