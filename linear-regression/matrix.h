#ifndef MATRIX_H
#define MATRIX_H

typedef struct Matrix {
  int rows;
  int cols;
  double** data;
} Matrix;

Matrix* makeMatrix(int n_rows, int n_cols);

Matrix* copyMatrix(double* data, int n_rows, int n_cols);

void printMatrix(Matrix* m);

void testMatrix();

#endif // MATRIX_H
