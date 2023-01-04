//
// Created by User on 6/5/2022.
//

#ifndef LINEARALGEBRA_VECTOR_H
#define LINEARALGEBRA_VECTOR_H

#include <string>
#include <vector>
#include "cassert"

enum ORIENTATION
{
    ROW = false,
    COL = true,
};


class Vector {
public:

    Vector(int size, bool orientation = ORIENTATION::COL);

    ~Vector();

    int& operator[](int index);
    Vector& operator+(Vector pGiven);
    Vector& operator-(Vector pGiven);
    Vector& operator*(Vector pGiven);

    int at(int index);
    void fill(const int* newValues);
    void transpose();
    float magnitude();

    inline int size() { return m_length; }

private:

    int* m_pData;
    int m_length;
    bool m_orientation; // true:= column vector; false:= row vector
};


#endif //LINEARALGEBRA_VECTOR_H
