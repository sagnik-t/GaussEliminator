#include <vector>

#include "GEA.h"

void GaussianElimination::free_vars()
{
    for (int col = 0; col < matrix.get_cols(); col++)
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
            for (int row = 0; row < matrix.get_rows(); row++)
            {
                if (matrix[row][col] != 0)
                {
                    freeRowIndex = row;
                    break;
                }
            }
            frees.emplace_back(freeRowIndex, col);
        }
    }
}

bool GaussianElimination::is_unique() const
{
    return frees.empty();
}