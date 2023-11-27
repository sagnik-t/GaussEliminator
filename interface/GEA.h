#pragma once

#ifndef GEA_H
#define GEA_H

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

#include "overloads.h"
#include "matrix.h"

class GaussianElimination
{
private:
    Matrix<double> matrix;
    std::vector<double> values;
    std::vector<std::pair<int, int>> pivots;
    std::vector<std::pair<int, int>> frees;

public:
    GaussianElimination(Matrix<double> matrix) : matrix(std::move(matrix))
    {}
    
    void forward_phase();
    void backward_phase();
    void free_vars();
    bool is_unique() const;
};

#endif