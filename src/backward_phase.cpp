#include <vector>

#include "GEA.h"

void GaussianElimination::backward_phase()
{
    reverse(pivots.begin(), pivots.end());

    for (auto pivot : pivots)
    {
        int curr_row = pivot.first, curr_col = pivot.second;

        for (int row = 0; row < matrix.get_rows(); row++)
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