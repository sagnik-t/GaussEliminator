#include <vector>

#include "GEA.h"

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
            frees.push_back(std::make_pair(freeRowIndex, col));
        }
    }
}