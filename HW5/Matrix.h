#ifndef MATRIX_H
#define MATRIX_H

// Class to represent a matrix of floats for our simulation
class Matrix {
  public:
    // Constructors
    Matrix(int rows, int cols);
    Matrix(const Matrix& a);

    // Destructor
    ~Matrix();

    // Set position i,j to value
    void set(int i, int j, float value);

    // Get a position i,j
    float get(int i, int j) const;

    // Prints the matrix for debugging
    void print();

    // Operator for multiplication
    Matrix operator*(const Matrix& y);

    // Return dimensions
    int getRows() const;
    int getCols() const;

  private:
    float ** matrix;
    int rows;
    int cols;

};

#endif // MATRIX_H
