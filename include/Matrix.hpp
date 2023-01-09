
#ifndef LINEARALGEBRA_MATRIX_HPP
#define LINEARALGEBRA_MATRIX_HPP

#include "Vector.hpp"
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
    explicit Matrix(int newRows = 3, int newCols = 3);
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

    void insert(int value, uint32_t x, uint32_t y);   // explicit method to place value at position

    std::string to_string();
    void print();

    inline int getRowSize() const { return m_nRows; }
    inline int getColSize() const { return m_nCols; }

protected:

private:

    int* m_pValues;

    int m_nElements;
    int m_nRows;
    int m_nCols;

};


#endif //LINEARALGEBRA_MATRIX_HPP
