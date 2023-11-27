### FORWARD_PHASE(matrix):

	for curr_row=0 to matrix.get_rows - 1:

##### finding the pivot column
		for col=0 to matrix.get_cols - 1:
			if matrix[[col]].sum() != 0:
				pivot_col = col
				break

##### finding the pivot
		for row=curr_row to matrix.get_rows - 1:
			if matrix[row][pivot_col] != 0
				pivot = row
				break

##### moving the pivot to the pivot position	
		SWAP(matrix[curr_row], matrix[pivot])

##### creating zeroes
		for row=curr_row+1 to matrix.get_rows - 1:
			scale = matrix[row][pivot_col]/matrix[pivot][pivot_col]
			matrix[row] = matrix[row] - scale * matrix[pivot]

##### storing the pivot positions
		pivots.append(PAIR(curr_row, pivot_col))