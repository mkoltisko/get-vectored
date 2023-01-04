
#ifndef LINEARALGEBRA_MATRIX_H
#define LINEARALGEBRA_MATRIX_H

#include "Vector.h"
#include <string>

enum DIRECTION
{
    TOP     = 0,
    BOTTOM  = 1,
    LEFT    = 2,
    RIGHT   = 3,
};

class Matrix {
public:
    Matrix(int newRows = 3, int newCols = 3);
    ~Matrix();

    int& operator[](int index); // return value at linear index
    Matrix& operator+(Matrix pMatrix);
    Matrix& operator-(Matrix pMatrix);
    Matrix& operator*(Matrix pMatrix);

    void transpose();
    void inverse();
    float determinant();

    int& at(int x, int y);  // method to change reference at position
    int get(int x, int y);  // method to return value at place
    void swap(int x1, int y1, int x2, int y2);

    void insert(int value, int x, int y);   // explicit method to place value at position
    void append(Vector* pVector, DIRECTION direction);  // add on new vector to directional side of matrix

    std::string to_string();
    void print();

    inline const int getRowSize() { return m_nRows; }
    inline const int getColSize() { return m_nCols; }

protected:

private:

    int* m_pValues;

    int m_nElements;
    int m_nRows;
    int m_nCols;

};


#endif //LINEARALGEBRA_MATRIX_H
