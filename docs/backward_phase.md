### BACKWARD_PHASE(matrix):

##### Start from the rightmost pivot
    pivots.reverse()
    for pivot in pivots:

##### Creating zeroes
        curr_row, curr_col = pivot.first, pivot.second
        for row=0 to matrix.get_rows - 1:
            if row != curr_row:
                scale = matrix[row][curr_col]/matrix[curr_row][curr_col]
                matrix[row] = matrix[row] - scale * matrix[curr_row]

##### Scaling the pivots
        if matrix[curr_row][curr_col] != 1:
            scale = 1 / matrix[curr_row][curr_col]
            matrix[curr_row] = matrix[curr_row] * scale
