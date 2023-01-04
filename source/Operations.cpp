
#include "../include/Operations.hpp"
#include "../include/Properties.hpp"

float dot(Vector *first, Vector *second)
{
    assert(first->size() == second->size());

    float sum = 0;
    for (int i = 0; i < first->size(); ++i) {
        sum = sum + (first->at(i) * second->at(i));
    }
    return sum;
}

float angle(Vector *first, Vector *second)
{
    assert(!isZeroVector(first));
    assert(!isZeroVector(second));
    return acos(dot(first, second) / (first->magnitude() * second->magnitude())) * (180/PI);
}
