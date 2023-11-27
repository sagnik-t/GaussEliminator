#include <vector>
#include <algorithm>
#include <functional>

#include "GEA.h"

void GaussianElimination::forward_phase()
{
    std::function<bool(double)> findNonZero = [](double val) -> bool {return val != 0;};
    for (int curr_row = 0; curr_row < matrix.getrows(); curr_row++)
    {
        int pivot_col, pivot_row;
        for (int col = 0; col < matrix.getcols(); col++)
        {
            std::vector<double>::iterator nonZero_itr = find_if(matrix.col(col).begin(), matrix.col(col).end(), findNonZero); // NOLINT(*-use-auto)
            if (nonZero_itr != matrix.col(col).end())
            {
                pivot_col = col;
                break;
            }
        }
        for (int row = curr_row; row < matrix.getrows(); row++)
        {
            if (matrix[row][pivot_col] != 0)
            {
                pivot_row = row;
                break;
            }
        }
        matrix.swap(curr_row, pivot_row);
        for (int row = curr_row + 1; row < matrix.getrows(); row++)
        {
            double scale = matrix[row][pivot_col]/matrix[pivot_row][pivot_col];
            matrix[row] = matrix[row] - matrix[pivot_row] * scale;
        }
        pivots.push_back(std::make_pair(curr_row, pivot_col));
    }
}