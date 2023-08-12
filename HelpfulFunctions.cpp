
#include "HelpfulFunctions.hpp"

#include "LinearAlgebra/LinearObject.hpp"
#include "DataStructures/LinkedList.hpp"

// linear zero-index to zero-indexed coordinates
SUBSCRIPT ind2sub(unsigned int linearIndex, const LinearObject& obj)
{
    assertMessage(linearIndex < obj.size(), "Index out of bounds");
    return SUBSCRIPT(linearIndex / obj.getNumColumns(), linearIndex % obj.getNumColumns());
}

unsigned int sub2ind(SUBSCRIPT coord, const LinearObject &obj)
{
    assertMessage(coord.row < obj.getNumRows(), "Row index out of bounds");
    assertMessage(coord.col < obj.getNumColumns(), "Column index out of bounds");
    return (coord.row * obj.getNumColumns()) + coord.col;
}

void print(const std::string& message)
{
    std::cout << message << std::endl;
}

void print(const SUBSCRIPT& coords)
{
    std::cout << '(' << coords.row << ',' << coords.col << ')' << std::endl;
}

void print(const LinearObject& obj)
{
    print(obj.to_string());
}

template <typename T>
void print(const LinkedList<T>& list)
{
    print(list.to_string());
}


void assertMessage(bool condition, const std::string& message)
{
    if(!condition && !message.empty())
    {
        print(message);
    }
    assert(condition);
}

LinearObject Identity(unsigned int length)
{
    LinearObject I(length, length);
    for(int i = 0; i < length; ++i)
    {
        I[SUBSCRIPT(i, i)] = 1;
    }
    return I;
}

LinearObject Rx(float theta)
{
    LinearObject rx;
    rx[0] = 1;
    rx[SUBSCRIPT(1, 1)] = cos(theta);
    rx[SUBSCRIPT(1, 2)] = -sin(theta);
    rx[SUBSCRIPT(2, 1)] = sin(theta);
    rx[SUBSCRIPT(2, 2)] = cos(theta);
    return rx;
}

LinearObject Ry(float theta)
{
    LinearObject ry;
    ry[SUBSCRIPT(0, 0)] = cos(theta);
    ry[SUBSCRIPT(0, 2)] = sin(theta);
    ry[SUBSCRIPT(1, 1)] = 1;
    ry[SUBSCRIPT(2, 0)] = -sin(theta);
    ry[SUBSCRIPT(2, 2)] = cos(theta);
    return ry;
}

LinearObject Rz(float theta)
{
    LinearObject rz;
    rz[SUBSCRIPT(0, 0)] = cos(theta);
    rz[SUBSCRIPT(0, 1)] = -sin(theta);
    rz[SUBSCRIPT(1, 0)] = sin(theta);
    rz[SUBSCRIPT(1, 1)] = cos(theta);
    rz[SUBSCRIPT(2, 2)] = 1;
    return rz;}
