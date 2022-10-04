#include <stdbool.h>
#include <stdio.h>

int main(void)
{
	float a[10][10], a_inv[10][10];
	puts("Calculating matrix inverse\n");
	printf("Enter the number of rows and columns you want to enter in the matrix: ");
	int row, col;
	scanf("%d%d", &row, &col);
	if (row != col) {
		printf("Could not calculate the inverse of a non-square matrix\n");
		return 1;
	}
	int n = row;
	printf("Enter the %d elements for the matrix:\n", n * n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%f", &a[i][j]);
		}
	}
	/* Initialise `a_inv` with the identity matrix. */
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			a_inv[i][j] = i == j ? 1.0f : 0.0f;
		}
	}
	/* NOTE: Every operation is done the same way on both matrices. */
	for (int z = 0; z < n; z++) {
		int fi;
		/* Find a row whose z-th column is non-zero. */
		for (fi = z; fi < n; fi++)
			if (a[fi][z] != 0.0f)
				break;
		if (fi == n) {
			continue;
		}
		/* If it is not the current row ... */
		if (fi != z) {
			/* ... swap them. */
			int t, tt, k;
			for (k = 0; k < n; k++) {
				t = a[z][k];
				tt = a_inv[z][k];
				a[z][k] = a[fi][k];
				a_inv[z][k] = a_inv[fi][k];
				a[fi][k] = t;
				a_inv[fi][k] = tt;
			}
		}
		/* Multiply each element of this row by p to get 1 in
		 * z-th column. */
		float p = 1.0f / a[z][z];
		for (int k = 0; k < n; k++) {
			a[z][k] = a[z][k] * p;
			a_inv[z][k] = a_inv[z][k] * p;
		}
		for (int k = 0; k < n; k++) {
			/* Except current row ... */
			if (k == z) continue;
			if (a[k][z] == 0.0f) continue;
			/* ... subtract every row by a multiple of the
			 * current row such that the value at z-th column
			 * of that row is zero */
			float f = a[k][z];
			for (int c = 0; c < n; c++) {
				a[k][c] -= f * a[z][c];
				a_inv[k][c] -= f * a_inv[z][c];
			}
		}
	}
	/* Check whether the input matrix could be transformed into
	 * the identity matrix ... */
	bool noinv = false;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i != j && a[i][j] != 0.0f)
				noinv = true;
		}
	}
	/* ... Otherwise, the matrix has no inverse. */
	if (noinv) {
		printf("The given matrix has no inverse\n");
		return 0;
	}
	/* Display the inverted matrix. */
	puts("The elements of the inverse matrix are:");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%g\t", a_inv[i][j]);
		}
		printf("\n");
	}
	return 0;
}

