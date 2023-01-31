
#include "HelpfulFunctions.hpp"

#include "LinearObject.hpp"

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

void assertMessage(bool condition, const std::string& message)
{
    if(!condition && !message.empty())
    {
        print(message);
    }
    assert(condition);
}
