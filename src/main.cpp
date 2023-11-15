#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <numeric>
#include "overloads.h"
#include "matrix.h"
using namespace std;

class GaussianElimination
{
private:
    Matrix<double> matrix;

public:
    GaussianElimination(Matrix<double> matrix) : matrix(matrix)
    {}
    
};