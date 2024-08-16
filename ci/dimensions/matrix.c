#include <stdio.h>

int main(void) {
  // The result of multiplying a 2x3 matrix
  // with a 3x2 matrix will be a 2x2 matrix.
  // Here is how you can do the matrix multiplication in C:
  int matrixA[2][3] = {
      {1, 4, 2},
      {3, 6, 8}};

  int matrixB[3][2] = {
      {5, 2},
      {7, 1},
      {9, 3}};

  int result[2][2];

  // Initialize result matrix to zero
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      result[i][j] = 0;
    }
  }

  // Matrix multiplication
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 3; k++) {
        result[i][j] += matrixA[i][k] * matrixB[k][j];
      }
    }
  }

  // Print the result
  printf("Result of multiplication:\n");
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }

  return 0;
}
