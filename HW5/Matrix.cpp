#include "Matrix.h"
#include <iostream>
#include <assert.h>

Matrix::Matrix(int rows, int cols) {
  this->rows = rows;
  this->cols = cols;
  this->matrix = new float*[rows];
  for(int i = 0; i < rows; i++) {
      this->matrix[i] = new float[cols];
  }

  for(int i = 0; i < this->rows; i++) {
    for(int j = 0; j < this->cols; j++) {
      this->matrix[i][j] = 0.0;
    }
  }
}

Matrix::Matrix(const Matrix& a){
  this->rows = a.getRows();
  this->cols = a.getCols();
  this->matrix = new float*[rows];
  for(int i = 0; i < rows; i++) {
      this->matrix[i] = new float[cols];
  }
  for(int i = 0; i < this->rows; i++) {
    for(int j = 0; j < this->cols; j++) {
      this->matrix[i][j] = a.get(i,j);
    }
  }
}

float Matrix::get(int i, int j) const {
  return this->matrix[i][j];
}

void Matrix::set(int i, int j, float value) {
  if (i >= 0 && i < this->rows && j >=0 && j < this->cols)
    this->matrix[i][j] = value;
}

int Matrix::getRows() const {
  return this->rows;
}

int Matrix::getCols() const {
  return this->cols;
}

// Prints the matrix for debugging
void Matrix::print() {
  for(int i = 0; i < this->rows; i++) {
    for(int j = 0; j < this->cols; j++) {
      std::cout << this->matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

Matrix::~Matrix() {
  for(int i = 0; i < this->rows; i++) {
    delete [] this->matrix[i];
  }
  delete [] this->matrix;
}

// For i from 1 to n:
// For j from 1 to p:
// Let sum = 0
// For k from 1 to m:
// Set sum ← sum + Aik × Bkj
// Set Cij ← sum
// Return C

// Operator for multiplication
Matrix Matrix::operator*(const Matrix& y) {
  assert(this->cols == y.getRows());
  Matrix output(this->rows, y.getCols());
  for (int i = 0; i < this->rows; i++) {
    for (int j = 0; j < y.getCols(); j++) {
      float sum = 0.0;
      for (int k = 0; k < this->cols; k++) {
        sum += this->get(i,k) * y.get(k, j);
      }
      output.set(i, j, sum);
    }
  }

  return output;
}
