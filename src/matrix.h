#pragma once

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <algorithm>

template<class T>
class Matrix
{
private:
    size_t rows, cols;
    std::vector<std::vector<T>> matrix;

public:
    Matrix(size_t rows, size_t cols) : rows(rows), cols(cols), matrix(rows, std::vector<T>(cols)) {}
 
    Matrix(const std::vector<std::vector<T>>& v) : rows(v.size()), cols(v[0].size()), matrix(v) {}

    //getters
    size_t rows() const
    {return this->rows;}
    size_t cols() const
    {return this->cols;}

    //operations overloads
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const T& k) const;
    Matrix operator/(const T& k) const;
    std::vector<T> operator[](const int& row) const;
    std::vector<T> col(const int &col) const;

    void swap(const int& row1, const int& row2);

    static void populate(Matrix& mat);
    static void print(const Matrix& mat);
};

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix& other) const
{
    Matrix<T> result(rows, cols);
    for (int row = 0; row < rows; row++)
        result.matrix[row] = this->matrix[row] + other.matrix[row];
    return result;
}

template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix& other) const
{
    Matrix<T> result(rows, cols);
    for (int row = 0; row < rows; row++)
        result.matrix[row] = this->matrix[row] - other.matrix[row];
    return result;
}

template<class T>
Matrix<T> Matrix<T>::operator*(const T& k) const
{
    Matrix<T> result(rows, cols);
    for (int row = 0; row < rows; row++)
        result.matrix[row] = this->matrix[row] * k;
    return result;
}

template<class T>
Matrix<T> Matrix<T>::operator/(const T& k) const
{
    Matrix<T> result(rows, cols);
    for (int row = 0; row < rows; row++)
        result.matrix[row] = this->matrix[row] / k;
    return result;
}

template<class T>
inline std::vector<T> Matrix<T>::operator[](const int& row) const
{
    return this->matrix[row];
}

template<class T>
std::vector<T> Matrix<T>::col(const int &col) const
{
    if (col >= this->cols)
        throw std::out_of_range("Column index out of bounds");

    std::vector<T> column;
    for (int row = 0; row < this->rows; row++)
        column.push_back(this->matrix[row][col]);
    return column;
}

//interchange columns
template<class T>
inline void Matrix<T>::swap(const int& row1, const int& row2)
{
    std::swap_ranges(matrix[row1].begin(), matrix[row1].end(), matrix[row2].begin());
}

template<class T>
void Matrix<T>::populate(Matrix& mat)
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

template<class T>
void Matrix<T>::print(const Matrix& mat)
{
    for (int i = 0; i < mat.rows; ++i)
    {
        for (int j = 0; j < mat.cols; ++j)
            std::cout << mat[i][j] << " ";
        std::cout << std::endl;
    }
}

#endif