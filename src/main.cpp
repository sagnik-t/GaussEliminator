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
    vector<pair<int, int>> pivots;

public:
    GaussianElimination(Matrix<double> matrix) : matrix(matrix)
    {}
    
    void forward_phase();
    void backward_phase();
};

void GaussianElimination::forward_phase()
{
    for (int curr_row = 0; curr_row < matrix.rows(); curr_row++)
    {
        int pivot_col, pivot_row;
        for (int col = 0; col < matrix.cols(); col++)
        {
            if (accumulate(matrix.col(col).begin(), matrix.col(col).end(), 0) != 0)
            {
                pivot_col = col;
                break;
            }
        }
        for (int row = curr_row; row < matrix.rows(); row++)
        {
            if (matrix[row][pivot_col] != 0)
            {
                pivot_row = row;
                break;
            }
        }
        matrix.swap(curr_row, pivot_row);
        for (int row = curr_row + 1; row < matrix.rows(); row++)
        {
            double scale = matrix[row][pivot_col]/matrix[pivot_row][pivot_col];
            matrix[row] = matrix[row] - matrix[pivot_row] * scale;
        }
        pivots.push_back(make_pair(curr_row, pivot_col));
    }
}