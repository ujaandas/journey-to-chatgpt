#include "./matrix.h"
#include <stdio.h>
#include <stdlib.h>

Matrix* makeMatrix(int n_rows, int n_cols) {
  struct Matrix* m = malloc(sizeof(Matrix));

  m->rows = n_rows;
  m->cols = n_cols;

  double** data = malloc(sizeof(double*) * n_rows);

  for (int i = 0; i < n_rows; i++) {
    data[i] = calloc(n_cols, sizeof(double));
  }
  
  m->data = data;

  return m;
}

Matrix* copyMatrix(double* data, int n_rows, int n_cols) {
  struct Matrix *matrix = mk_matrix(n_rows, n_cols);

  for (int i = 0; i < n_rows; i++) {
    for (int j = 0; j < n_cols; j++) {
      matrix->data[i][j] = data[n_cols * i + j];
    }
  }

  return matrix;
}

void printMatrix(Matrix* m) {
  for (int i = 0; i < m->rows; i++) {
    printf("\n");
    for (int j = 0; j < m->cols; j++) {
      printf("%f\t", m->data[i][j]);
    }
  }
}

void testMatrix(){
  double a[] = {
    1, 2, 3,
    4, 5, 6,
    7, 8, 9,
    10, 11, 12
  };

  Matrix* m = cp_matrix(a, 3, 3);
  print_matrix(m);
}

