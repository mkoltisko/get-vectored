
#include "HelpfulFunctions.hpp"

#include "LinearObject.hpp"

SUBSCRIPT ind2sub(unsigned int linearIndex, unsigned int nRows, unsigned int nCols)
{
    if(linearIndex < nRows)
    {
        ++nRows;
    }
    return SUBSCRIPT(linearIndex / nRows, linearIndex % nCols);
}

unsigned int sub2ind(SUBSCRIPT coord, unsigned int nRows, unsigned int nCols)
{
    return (coord.row * nCols) + coord.col;
}

void print(const std::string &message)
{
    std::cout << message << std::endl;
}

void print(const SUBSCRIPT& coords)
{
    std::cout << '(' << coords.row << ',' << coords.col << ')' << std::endl;
}

void print(const LinearObject* matrix)
{
    assert(matrix != nullptr);
    print(matrix->to_string());
}

void assertMessage(bool condition, const std::string& message)
{
    if (condition)
    {
        // true so nothing else required
        return;
    }
    if(!message.empty())
    {
        print(message);
    }
    assert(condition);
}
