#pragma once

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <algorithm>

#include "iterator.h"

template<class T>
class Matrix
{
private:
    size_t rows, cols;
    std::vector<std::vector<T>> matrix;

public:
    Matrix(size_t rows, size_t cols) : rows(rows), cols(cols), matrix(rows, std::vector<T>(cols)) {}
 
    explicit Matrix(const std::vector<std::vector<T>>& v) : rows(v.size()), cols(v[0].size()), matrix(v) {}

    //row getter
    size_t get_rows() const
    {return this->rows;}
    //column getter
    size_t get_cols() const
    {return this->cols;}

    //iterators

    Iterator<T> begin() const;
    Iterator<T> end() const;

    //operations overloads

    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const T& k) const;
    Matrix operator/(const T& k) const;
    std::vector<T> operator[](const int& row) const;
    std::vector<T> col(const int &col) const;

    //interchange columns
    void swap(const int& row1, const int& row2);

    //basic I/O
    static void populate(Matrix& mat);
    static void print(const Matrix& mat);
};

#endif