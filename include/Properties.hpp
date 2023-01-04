
#ifndef LINEARALGEBRA_PROPERTIES_HPP
#define LINEARALGEBRA_PROPERTIES_HPP

#include "Vector.hpp"
#include "Matrix.hpp"
#include "Operations.hpp"

bool isZeroVector(Vector* pVector);

bool isSquareMatrix(Matrix* pMatrix);

bool isInvertible(Matrix* pMatrix);



#endif //LINEARALGEBRA_PROPERTIES_HPP
