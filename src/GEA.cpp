#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include "overloads.h"
#include "matrix.h"
using namespace std;

class GaussianElimination
{
private:
    Matrix<double> matrix;
    vector<pair<int, int>> pivots;
    vector<pair<int, int>> frees;

public:
    GaussianElimination(Matrix<double> matrix) : matrix(matrix)
    {}
    
    void forward_phase();
    void backward_phase();
    void free_vars();
};

void GaussianElimination::forward_phase()
{
    function<bool(double)> findNonZero = [](double val) -> bool {return val != 0;};
    for (int curr_row = 0; curr_row < matrix.rows(); curr_row++)
    {
        int pivot_col, pivot_row;
        for (int col = 0; col < matrix.cols(); col++)
        {
            vector<double>::iterator nonZero_itr = find_if(matrix.col(col).begin(), matrix.col(col).end(), findNonZero);
            if (nonZero_itr != matrix.col(col).end())
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

void GaussianElimination::backward_phase()
{
    reverse(pivots.begin(), pivots.end());

    for (int i = 0; i < pivots.size(); i++)
    {
        pair<int, int> pivot = pivots[i];
        int curr_row = pivot.first, curr_col = pivot.second;

        for (int row = 0; row < matrix.rows(); row++)
        {
            if (row != curr_row)
            {
                double scale = matrix[row][curr_col]/matrix[curr_row][curr_col];
                matrix[row] = matrix[row] - matrix[curr_row] * scale;
            }
        }
        
        if (matrix[curr_row][curr_col] != 1)
        {
            double scale = 1 / matrix[curr_row][curr_col];
            matrix[curr_row] = matrix[curr_row] * scale;
        }
    }
}

void GaussianElimination::free_vars()
{
    for (int col = 0; col < matrix.cols(); col++)
    {
        bool hasPivot = false;
        for (const auto& pivot : pivots)
        {
            if (pivot.second == col)
            {
                hasPivot = true;
                break;
            }
        }

        if (!hasPivot)
        {
            int freeRowIndex = -1;
            for (int row = 0; row < matrix.rows(); row++)
            {
                if (matrix[row][col] != 0)
                {
                    freeRowIndex = row;
                    break;
                }
            }
            frees.push_back(make_pair(freeRowIndex, col));
        }
    }
}
