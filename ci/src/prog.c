#include <stdio.h>

int main() {
  int n = 5;

  // Right Triangle
  for (int row = 1; row <= n; row++) {
    for (int col = 1; col <= row; col++) {
      printf("* ");
    }
    printf("\n");
  }
  printf("\n");

  // Left Triangle
  for (int row = 1; row <= n; row++) {
    for (int col = row; col <= n; col++) {
      printf("* ");
    }
    printf("\n");
  }
  printf("\n");

  // Right side Triangle
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      printf(" ");
    }
    for (int j = 1; j <= i; j++) {
      printf("* ");
    }
    printf("\n");
  }
  printf("\n");

  // Right side Triangle 
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      printf(" ");
    }
    for (int j = i; j <= n; j++) {
      printf("* ");
    }
    printf("\n");
  }
  printf("\n");

  // Hill Pattern 
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      printf(" ");
    }
    for (int j = 1; j < i; j++) {
      printf("* ");
    }
    for (int j = 1; j <= i; j++) {
      printf("* ");
    }
    printf("\n");
  }
  printf("\n");

  // Hill Pattern reverse
  for (int i = i; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      printf(" ");
    }
    for (int j = i; j < n; j++) {
      printf("* ");
    }
    for (int j = i; j <= n; j++) {
      printf("* ");
    }
    printf("\n");
  }
  printf("\n");

  // Diamond Pattern
  for (int i = 1; i < n; i++) {
    for (int j = i; j <= n; j++) {
      printf(" ");
    }
    for (int j = 1; j <= i; j++) {
      printf("* ");
    }
    for (int j = 1; j <= i; j++) {
      printf("* ");
    }
    printf("\n");
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= i; j++) {
      printf(" ");
    }
    for (int j = i; j <=n; j++) {
      printf("* ");
    }
    for (int j = i; j <= n; j++) {
      printf("* ");
    }
    printf("\n");
  }
  printf("\n");

  for (int k = 1; k <= n; k++) {
    for (int c = 1; c <= n - k; c++)
      printf(" ");

    for (int c = 1; c <= 2 * (k - 1); c++)
      printf("* ");

    printf("\n");
  }

  for (int k = 1; k <= n - 1; k++) {
    for (int c = 1; c <= k; c++)
      printf(" ");

    for (int c = 1; c <= 2 * (n - k) - 1; c++)
      printf("* ");

    printf("\n");
  }
  return 0;
}