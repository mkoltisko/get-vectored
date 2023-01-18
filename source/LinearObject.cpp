

#include "LinearObject.hpp"

LinearObject::LinearObject(unsigned int rows, unsigned int cols) :
    m_NumRows(rows),
    m_NumColumns(cols),
    m_NumElements(rows * cols)
{
    m_pData = new float[rows * cols]{};
}

// Mainly used to create an augmented 4x4 matrix from (R, t)
LinearObject::LinearObject(LinearObject* first, LinearObject* second)
{
    assertMessage(first->m_NumRows == second->m_NumRows, "Must have same number of rows");
    m_NumRows = first->m_NumRows;
    m_NumColumns = first->m_NumColumns + second->m_NumColumns;
    m_NumElements = m_NumRows * m_NumColumns;
    m_pData  = new float[m_NumElements]{};
    // fill in values and make the rest identity matrix
}

LinearObject::~LinearObject()
{
    delete [] m_pData;
}

float& LinearObject::operator[](unsigned int linearIndex)
{
    return m_pData[linearIndex];
}

float& LinearObject::operator[](SUBSCRIPT coords)
{
    return m_pData[sub2ind(coords, m_NumRows, m_NumColumns)];
}

float& LinearObject::operator()(unsigned int x, unsigned int y)
{
//    assertMessage(x < m_NumColumns, "Row index out of bounds");
//    assertMessage(y < m_NumRows, "Column index out of bounds");
    return m_pData[(x * m_NumColumns) + y];
}

LinearObject LinearObject::operator+(float scalar)
{
    LinearObject result{};
    for(int i = 0; i < m_NumElements; ++i)
    {
        result[i] = m_pData[i] + scalar;
    }
    return result;
}

LinearObject LinearObject::operator+(LinearObject &other)
{
    assertMessage(this->dimensions() == other.dimensions(), "Objects must have same dimensions");
    LinearObject result{};
    for(int i = 0; i < m_NumElements; ++i)
    {
        result[i] = m_pData[i] + other[i];
    }
    return result;
}

LinearObject LinearObject::operator-(float scalar)
{
    LinearObject result{};
    for(int i = 0; i < m_NumElements; ++i)
    {
        result[i] = m_pData[i] - scalar;
    }
    return result;
}

LinearObject LinearObject::operator-(LinearObject &other)
{
    assertMessage(this->dimensions() == other.dimensions(), "Objects must have same dimensions");
    LinearObject result{};
    for(int i = 0; i < m_NumElements; ++i)
    {
        result[i] = m_pData[i] - other[i];
    }
    return result;
}

LinearObject LinearObject::operator*(float scalar)
{
    LinearObject result{};
    for(int i = 0; i < m_NumElements; ++i)
    {
        result[i] = m_pData[i] * scalar;
    }
    return result;
}

LinearObject LinearObject::operator*(LinearObject &other)
{
    assertMessage(this->dimensions() == other.dimensions(), "Objects must have same dimensions");
    LinearObject result{};
    for(int i = 0; i < m_NumElements; ++i)
    {
        result[i] = m_pData[i] * other[i];
    }
    return result;
}

LinearObject LinearObject::operator/(float scalar)
{
    LinearObject result{};
    for(int i = 0; i < m_NumElements; ++i)
    {
        result[i] = m_pData[i] / scalar;
    }
    return result;
}

LinearObject LinearObject::operator/(LinearObject &other)
{
    assertMessage(this->dimensions() == other.dimensions(), "Objects must have same dimensions");
    LinearObject result{};
    for(int i = 0; i < m_NumElements; ++i)
    {
        result[i] = m_pData[i] / other[i];
    }
    return result;
}

float LinearObject::at(unsigned int index)
{
    return m_pData[index];
}

std::string LinearObject::to_string() const
{
    std::stringstream result;
    for(int i = 0; i < m_NumElements; ++i)
    {
        result << (m_pData[i]);
        if(((i+1) % m_NumColumns == 0) && (i+1 != m_NumElements))
        {
            result << '\n';
        }
    }
    result << std::endl;
    return result.str();
}

void LinearObject::transpose()
{
    if(isVector(this))
    {
        std::swap(m_NumRows, m_NumColumns);
        return;
    }
    auto* newOrder = new float[m_NumElements]{};
    for(int i  = 0; i < m_NumElements; ++i)
    {
        SUBSCRIPT oldCoord = ind2sub(i, m_NumRows, m_NumColumns);
        SUBSCRIPT newCoord(oldCoord.col, oldCoord.row);
        unsigned int newIndex = sub2ind(newCoord, m_NumColumns, m_NumRows);
        newOrder[newIndex] = m_pData[i];
    }
    delete [] m_pData;
    m_pData = newOrder;
    std::swap(m_NumRows, m_NumColumns);
}

float LinearObject::magnitude()
{
    return 0;
}

float LinearObject::determinant()
{
    return 0;
}

LinearObject LinearObject::inverse()
{
    return LinearObject();
}
