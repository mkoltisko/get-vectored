
#ifndef LINEARALGEBRA_OPERATIONS_HPP
#define LINEARALGEBRA_OPERATIONS_HPP

#include <string>
#include <cmath>

#include "LinearObject.hpp"
#include "Properties.hpp"
#include "../HelpfulFunctions.hpp"

static const float PI = 3.14159F;

// Vector operations
double dot(LinearObject* vecLeft, LinearObject* vecRight);
LinearObject cross(LinearObject* vecLeft, LinearObject* vecRight);
double angle(LinearObject* vecLeft, LinearObject* vecRight);

// Factorizations and decompositions
bool lu(LinearObject original, LinearObject& lower, LinearObject& upper);
bool qr(LinearObject original, LinearObject& q, LinearObject& r);
#endif //LINEARALGEBRA_OPERATIONS_HPP
