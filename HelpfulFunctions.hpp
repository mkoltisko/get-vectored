
#ifndef MATRIX_H_HELPFULFUNCTIONS_HPP
#define MATRIX_H_HELPFULFUNCTIONS_HPP

#include <iostream>
#include "Vector.hpp"

void print(const std::string& message)
{
    std::cout << message << std::endl;
}

void print(Vector* v)
{
    assert(v != nullptr);
    print(v->to_string());
}

void AssertMessage(bool condition, const std::string& message)
{
    if (!condition)
    {
        print(message);
        assert(condition);
    }
}

#endif //MATRIX_H_HELPFULFUNCTIONS_HPP
