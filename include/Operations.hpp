
#ifndef LINEARALGEBRA_OPERATIONS_HPP
#define LINEARALGEBRA_OPERATIONS_HPP

#include <string>
#include <cmath>

#include "Properties.hpp"
#include "Vector.hpp"
#include "Matrix.hpp"

static const float PI = 3.14159F;

inline void transpose(Vector* pVector) { pVector->transpose(); };

inline void transpose(Matrix* pMatrix) { pMatrix->transpose(); };

float dot(Vector *first, Vector *second);

float angle(Vector *first, Vector *second);

float determinant(Matrix pMatrix);

#endif //LINEARALGEBRA_OPERATIONS_HPP
