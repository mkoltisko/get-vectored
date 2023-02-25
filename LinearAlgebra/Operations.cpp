
#include "Operations.hpp"

double dot(LinearObject* vecLeft, LinearObject* vecRight)
{
    assert(vecLeft->size() == vecRight->size());

    double sum = 0;
    for (int i = 0; i < vecLeft->size(); ++i) {
        sum = sum + (vecLeft->at(i) * vecRight->at(i));
    }
    return sum;
}

LinearObject cross(LinearObject* vecLeft, LinearObject* vecRight)
{
    assertMessage(vecLeft->size() == 3, "Cross Product is not well defined outside 3D");
    assertMessage(vecRight->size() == 3, "Cross Product is not well defined outside 3D");

    LinearObject result;

    return result;
}

double angle(LinearObject* vecLeft, LinearObject* vecRight)
{
    assert(!isZeroVector(vecLeft));
    assert(!isZeroVector(vecRight));
    return acos(dot(vecLeft, vecRight) / (vecLeft->magnitude() * vecRight->magnitude())) * (180 / PI);
}
