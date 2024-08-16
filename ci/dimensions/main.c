#include <stdio.h>

// single dimension arrays or multidimensional arrays.

int main(void) {
  // A 2D array is also known as a matrix (a table of rows and columns).
  // The first dimension represents the number of rows [2],
  // while the second dimension represents the number of columns [3].
  int matrix[2][3] = {
      {1, 4, 2},
      {3, 6, 8}};

  // Access an element of a two-dimensional array,
  // by specify the index number of both the row and column.

  // Accesses the value of the element in the first row(0)
  // and third column(1) of the matrix array.
  printf("matrix[0][1]: %d\n", matrix[0][1]);  // Outputs 4
  printf("matrix[0][2]: %d\n", matrix[0][2]);  // Outputs 2
  printf("\n");

  printf("matrix[1][0]: %d\n", matrix[1][0]);  // Outputs 3
  printf("matrix[1][1]: %d\n", matrix[1][1]);  // Outputs 6
  printf("matrix[1][2]: %d\n", matrix[1][2]);  // Outputs 8
  printf("\n");

  // Get the length of the array
  int row = sizeof(matrix) / sizeof(matrix[0]);

  printf("Result of multiplication:\n");
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  return 0;
}
