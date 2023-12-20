#include "Matrix.h"

namespace miit::algebra {

    template <typename T>
    Matrix<T>::Matrix() {}

    template <typename T>
    Matrix<T>::Matrix(const Matrix<T>& other) : data(other.data) {

    }

    template <typename T>
    Matrix<T>::Matrix(Matrix<T>&& other) noexcept : data(std::move(other.data)) {
     
    }

    template <typename T>
    Matrix<T>::Matrix(size_t rows, size_t cols) : data(rows, std::vector<T>(cols, T())) {}

    template <typename T>
    Matrix<T>::~Matrix() {}

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

    template <typename T>
    Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other) {
        if (this != &other) {
            data = other.data;
        }
        return *this;
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