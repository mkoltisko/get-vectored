
#ifndef LINEARALGEBRA_OPERATIONS_HPP
#define LINEARALGEBRA_OPERATIONS_HPP

#include <string>
#include <cmath>

#include "LinearObject.hpp"
#include "Properties.hpp"
#include "../HelpfulFunctions.hpp"

static const float PI = 3.14159F;

double dot(LinearObject* vecLeft, LinearObject* vecRight);
LinearObject cross(LinearObject* vecLeft, LinearObject* vecRight);
double angle(LinearObject* vecLeft, LinearObject* vecRight);


#endif //LINEARALGEBRA_OPERATIONS_HPP
