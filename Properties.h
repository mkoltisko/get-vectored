
#ifndef LINEARALGEBRA_PROPERTIES_H
#define LINEARALGEBRA_PROPERTIES_H

#include "Vector.h"
#include "Matrix.h"
#include "Operations.h"

bool isZeroVector(Vector* pVector);

bool isSquareMatrix(Matrix* pMatrix);

bool isInvertible(Matrix* pMatrix);



#endif //LINEARALGEBRA_PROPERTIES_H
