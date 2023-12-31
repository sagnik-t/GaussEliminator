#include <vector>
#include <iostream>

#include "matrix.h"
#include "iterator.h"

template <class T>
Iterator<T> Matrix<T>::begin() const
{
    return Iterator<T>(this->matrix.begin());
}

template <class T>
Iterator<T> Matrix<T>::end() const
{
    return Iterator<T>(this->matrix.end());
}

template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix &other) const
{
    Matrix<T> result(this->get_rows(), this->get_cols());
    for (int row = 0; row < this->get_rows(); row++)
        result.matrix[row] = this->matrix[row] + other.matrix[row];
    return result;
}

template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix &other) const
{
    Matrix<T> result(this->get_rows(), this->get_cols());
    for (int row = 0; row < this->get_rows(); row++)
        result.matrix[row] = this->matrix[row] - other.matrix[row];
    return result;
}

template <class T>
Matrix<T> Matrix<T>::operator*(const T &k) const
{
    Matrix<T> result(this->get_rows(), this->get_cols());
    for (int row = 0; row < this->get_rows(); row++)
        result.matrix[row] = this->matrix[row] * k;
    return result;
}

template <class T>
Matrix<T> Matrix<T>::operator/(const T &k) const
{
    Matrix<T> result(this->get_rows(), this->get_cols());
    for (int row = 0; row < this->get_rows(); row++)
        result.matrix[row] = this->matrix[row] / k;
    return result;
}

template <class T>
inline std::vector<T> Matrix<T>::operator[](const int &row) const
{
    return this->matrix[row];
}

template <class T>
std::vector<T> Matrix<T>::col(const int &col) const
{
    if (col >= this->cols)
        throw std::out_of_range("Column index out of bounds");

    std::vector<T> column;
    for (int row = 0; row < this->rows; row++)
        column.push_back(this->matrix[row][col]);
    return column;
}

template <class T>
inline void Matrix<T>::swap(const int &row1, const int &row2)
{
    std::swap_ranges(matrix[row1].begin(), matrix[row1].end(), matrix[row2].begin());
}

template <class T>
void Matrix<T>::populate(Matrix &mat)
{
    for (int i = 0; i < mat.rows; ++i)
    {
        for (int j = 0; j < mat.cols; ++j)
        {
            std::cout << "[" << i << "][" << j << "]: ";
            std::cin >> mat.matrix[j][i];
        }
    }
}

template <class T>
void Matrix<T>::print(const Matrix &mat)
{
    for (int i = 0; i < mat.rows; ++i)
    {
        for (int j = 0; j < mat.cols; ++j)
            std::cout << mat[i][j] << " ";
        std::cout << std::endl;
    }
}
