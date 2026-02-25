#ifndef MATRIX_H
#define MATRIX_H

typedef struct Matrix {
  int rows;
  int cols;
  double** data;
} Matrix;

Matrix* mk_matrix(int n_rows, int n_cols);

Matrix* cp_matrix(double* data, int n_rows, int n_cols);

void print_matrix(Matrix* m);

void test_matrix();

#endif // MATRIX_H
