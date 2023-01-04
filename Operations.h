//
// Created by User on 6/5/2022.
//

#ifndef LINEARALGEBRA_OPERATIONS_H
#define LINEARALGEBRA_OPERATIONS_H

#include <string>
#include <cmath>

#include "Properties.h"
#include "Vector.h"
#include "Matrix.h"

static const float PI = 3.14159F;

inline void transpose(Vector* pVector) { pVector->transpose(); };

inline void transpose(Matrix* pMatrix) { pMatrix->transpose(); };

float dot(Vector *first, Vector *second);

float angle(Vector *first, Vector *second);

float determinant(Matrix pMatrix);

#endif //LINEARALGEBRA_OPERATIONS_H
