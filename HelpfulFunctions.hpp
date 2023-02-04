
#ifndef MATRIX_H_HELPFULFUNCTIONS_HPP
#define MATRIX_H_HELPFULFUNCTIONS_HPP

#include <iostream>
#include <cassert>

//#include <LinearObject.hpp>
class LinearObject;

struct SUBSCRIPT
{
    explicit SUBSCRIPT(unsigned int x=0, unsigned int y=0) :
        row(x),
        col(y)
    {}

    bool operator==(SUBSCRIPT other) const
    {
        return this->row == other.row && this->col == other.col;
    }

    unsigned int row;
    unsigned int col;
};

SUBSCRIPT ind2sub(unsigned int linearIndex, const LinearObject& obj);
unsigned int sub2ind(SUBSCRIPT coord, const LinearObject& obj);

void print(const std::string& message);
void print(const SUBSCRIPT& coords);
void print(const LinearObject& matrix);
void assertMessage(bool condition, const std::string& message = "");

LinearObject Identity(unsigned int length);
LinearObject Rx(float theta);
LinearObject Ry(float theta);
LinearObject Rz(float theta);

#endif //MATRIX_H_HELPFULFUNCTIONS_HPP
