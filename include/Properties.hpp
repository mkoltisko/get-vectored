
#ifndef LINEARALGEBRA_PROPERTIES_HPP
#define LINEARALGEBRA_PROPERTIES_HPP

#include "Operations.hpp"

class LinearObject;

bool isVector(LinearObject* pVector);
bool isColumnVector(LinearObject* pVector);
bool isRowVector(LinearObject* pVector);
bool isZeroVector(LinearObject* pVector);
bool isSquareMatrix(LinearObject* pMatrix);
bool isSymmetrical(LinearObject* pMatrix);
bool isInvertible(LinearObject* pMatrix);



#endif //LINEARALGEBRA_PROPERTIES_HPP
