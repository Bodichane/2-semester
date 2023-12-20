#pragma once

#include "Generator.h"
#include <iostream>
#include <initializer_list>
#include <sstream>
#include <stdexcept>
#include <vector> 

namespace miit::algebra
{
    template <typename T> class Matrix {
    private:
        size_t rows;
        size_t cols;
        std::vector<std::vector<T>> data;  

    public:
        /*
        * \brief Default constructor for Matrix.
        */
        Matrix();
        /*
        * \brief Copy constructor for Matrix.
        * \param other Another Matrix to copy.
        */
        Matrix(const Matrix<T>& other);
        /*
        * \brief Move constructor for Matrix.
        * \param other Another Matrix to move.
        */
        Matrix(Matrix<T>&& other) noexcept;
        /*
        * \brief Constructor to create a matrix with specified number of rows and columns.
        * \param rows Number of rows in the matrix.
        * \param cols Number of columns in the matrix.
        */
        Matrix(size_t rows, size_t cols);
        /*
        * \brief Destructor for Matrix.
        */
        ~Matrix();
        /*
        * \brief Convert the matrix to a string representation.
        * \return String representation of the matrix.
        */
        std::string toString() const;
        /*
        * \brief Gets the number of rows in the matrix.
        * \return The number of rows.
        */
        size_t getRows() const;
        /*
        * \brief Gets the number of columns in the matrix.
        * \return The number of columns.
        */
        size_t getColumns() const;
        /*
        * \brief Copy assignment operator for Matrix.
        * \param other Another Matrix to copy.
        * \return Reference to the assigned matrix.
        */
        Matrix<T>& operator=(const Matrix<T>& other);
        /*
        * \brief Left-shift operator for input from Generator.
        * \param generator Generator used to fill the matrix.
        * \return Reference to the modified matrix.
        */
        Matrix<T>& operator<<(const Generator& generator);
        /*
        * \brief Right-shift operator for output to std::ostream.
        * \param os Output stream to write the matrix.
        * \return Reference to the matrix.
        */
        Matrix<T>& operator>>(std::ostream& os) const;
        /**
        * \brief Access a specific element in the matrix by index.
        * \param row Row index of the element.
        * \param col Column index of the element.
        * \return Reference to the specified element.
        */
        T& operator()(size_t row, size_t col);
    };
}
