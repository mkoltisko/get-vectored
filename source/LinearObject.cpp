

#include "LinearObject.hpp"

LinearObject::LinearObject(unsigned int rows, unsigned int cols) :
    m_NumRows(rows),
    m_NumColumns(cols),
    m_NumElements(rows * cols)
{
    m_pData = new float[rows * cols]{};
}

LinearObject::LinearObject(const LinearObject& obj) :
    m_NumRows(obj.m_NumRows),
    m_NumColumns(obj.m_NumColumns),
    m_NumElements(obj.m_NumElements)
{
    m_pData = new float[obj.m_NumElements];
    for(int i = 0; i < obj.m_NumElements; ++i)
    {
        m_pData[i] = obj.m_pData[i];
    }
}

// Mainly used to create an augmented 4x4 matrix from (R, t)
LinearObject::LinearObject(LinearObject& left, LinearObject& right)
{
    assertMessage(left.m_NumRows == right.m_NumRows, "Must have same number of rows");

    unsigned int length = left.m_NumColumns + right.m_NumColumns;
    m_NumRows = length;
    m_NumColumns = length;
    m_NumElements = length * length;
    m_pData = new float[m_NumElements]{};

    // Start with an identity matrix
    for(int i = 0; i < length; ++i)
    {
        m_pData[sub2ind(SUBSCRIPT(i, i), *this)] = 1;
    }

    // Replace top left corner with left matrix
    for(int i = 0; i < left.m_NumElements; ++i)
    {
        SUBSCRIPT R_coord = ind2sub(i, left);
        m_pData[sub2ind(R_coord, *this)] = left[i];
    }

    // Place right matrix on the top after the left matrix
    for(int i = 0; i < right.m_NumElements; ++i)
    {
        SUBSCRIPT t_coord = ind2sub(i, right);
        t_coord.col += left.m_NumColumns;   // offset by the first matrix's columns
        m_pData[sub2ind(t_coord, *this)] = right[i];
    }
}

LinearObject::~LinearObject()
{
    delete [] m_pData;
    m_pData = nullptr;
}

LinearObject& LinearObject::operator=(const LinearObject& obj)
{
    if(this == &obj)
    {
        return *this;
    }
    m_NumRows = obj.getNumRows();
    m_NumColumns = obj.getNumColumns();
    m_NumElements = obj.size();
    delete [] m_pData;
    m_pData = new float[m_NumElements];
    for(int i = 0; i < obj.size(); ++i)
    {
        m_pData[i] = obj.m_pData[i];
    }
    return *this;
}


float LinearObject::operator[](unsigned int linearIndex) const
{
    assertMessage(linearIndex < m_NumElements, "Index out of bounds");
    return m_pData[linearIndex];
}

float& LinearObject::operator[](unsigned int linearIndex)
{
    assertMessage(linearIndex < m_NumElements, "Index out of bounds");
    return m_pData[linearIndex];
}

float LinearObject::operator[](SUBSCRIPT coord) const
{
    assertMessage(coord.row < m_NumRows, "Row index out of bounds");
    assertMessage(coord.col < m_NumColumns, "Column index out of bounds");
    return m_pData[sub2ind(coord, *this)];
}

float& LinearObject::operator[](SUBSCRIPT coord)
{
    assertMessage(coord.row < m_NumRows, "Row index out of bounds");
    assertMessage(coord.col < m_NumColumns, "Column index out of bounds");
    return m_pData[sub2ind(coord, *this)];
}

float& LinearObject::operator()(unsigned int x, unsigned int y)
{
    assertMessage(x < m_NumRows, "Row index out of bounds");
    assertMessage(y < m_NumColumns, "Column index out of bounds");
    return m_pData[(x * m_NumColumns) + y];
}

LinearObject LinearObject::operator+(float scalar)
{
    LinearObject result(m_NumRows, m_NumColumns);
    for(int i = 0; i < m_NumElements; ++i)
    {
        result.m_pData[i] = m_pData[i] + scalar;
    }
    return result;
}

LinearObject LinearObject::operator+(LinearObject& other)
{
    assertMessage(dimensions() == other.dimensions(), "Matrices must have same dimensions");
    LinearObject result(m_NumRows, m_NumColumns);
    for(int i = 0; i < m_NumElements; ++i)
    {
        result.m_pData[i] = m_pData[i] + other[i];
    }
    return result;
}

LinearObject LinearObject::operator-(float scalar)
{
    LinearObject result(m_NumRows, m_NumColumns);
    for(int i = 0; i < m_NumElements; ++i)
    {
        result.m_pData[i] = m_pData[i] - scalar;
    }
    return result;
}

LinearObject LinearObject::operator-(LinearObject &other)
{
    assertMessage(dimensions() == other.dimensions(), "Matrices must have same dimensions");
    LinearObject result(m_NumRows, m_NumColumns);
    for(int i = 0; i < m_NumElements; ++i)
    {
        result.m_pData[i] = m_pData[i] - other[i];
    }
    return result;
}

LinearObject LinearObject::operator*(float scalar)
{
    LinearObject result(m_NumRows, m_NumColumns);
    for(int i = 0; i < m_NumElements; ++i)
    {
        result.m_pData[i] = m_pData[i] * scalar;
    }
    return result;
}

LinearObject LinearObject::operator*(LinearObject &other)
{
    assertMessage(m_NumColumns == other.m_NumRows, "Objects must have complementary dimensions");
    unsigned int commonDim = m_NumColumns;
    LinearObject product(m_NumRows, other.m_NumColumns);
    for(int i = 0; i < product.size(); ++i)
    {
        SUBSCRIPT coord = ind2sub(i, product);
        float sum = 0;
        for(int j = 0; j < commonDim; ++j)
        {
            sum += (*this)[SUBSCRIPT(coord.row, j)] * other[SUBSCRIPT(j, coord.col)];
        }
        product[i] = sum;
    }
    return product;
}

LinearObject LinearObject::operator/(float scalar)
{
    LinearObject result(m_NumRows, m_NumColumns);
    for(int i = 0; i < m_NumElements; ++i)
    {
        result.m_pData[i] = m_pData[i] / scalar;
    }
    return result;
}

LinearObject LinearObject::operator/(LinearObject &other)
{
    assertMessage(isSquareMatrix(this) && isSquareMatrix(&other), "Matrix division is undefined for non-square matrices ");
    assertMessage(dimensions() == other.dimensions(), "Matrix division must be between matrices of the same dimensions");

    LinearObject result{};
    // multiply by inverse
    return result;
}

float LinearObject::at(unsigned int index)
{
    return m_pData[index];
}

float LinearObject::at(SUBSCRIPT coord)
{
    return m_pData[sub2ind(coord, *this)];
}

LinearObject LinearObject::getRow(unsigned int rowIndex)
{
    LinearObject row(1, m_NumColumns);
    for(int i = 0; i < m_NumColumns; ++i)
    {
        row.m_pData[i] = at(SUBSCRIPT(rowIndex, i));
    }
    return row;
}

LinearObject LinearObject::getColumn(unsigned int colIndex)
{
    LinearObject column(m_NumRows, 1);
    for(int i = 0; i < m_NumRows; ++i)
    {
        column.m_pData[i] = at(SUBSCRIPT(i, colIndex));
    }
    return column;
}

std::string LinearObject::to_string() const
{
    std::stringstream result;
    for(int i = 0; i < m_NumElements; ++i)
    {
        if(m_pData[i] > -1 && m_pData[i] < 10)
        {
            result << ' ';  // pad whitespace for single digits
        }
        result << (m_pData[i]) << ' ';
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

    LinearObject transposed(m_NumColumns, m_NumRows);
    for(int i = 0; i < m_NumElements; ++i)
    {
        SUBSCRIPT oldCoord = ind2sub(i, *this);
        std::swap(oldCoord.row, oldCoord.col);
        unsigned int newIndex = sub2ind(oldCoord, transposed);
        transposed.m_pData[newIndex] = m_pData[i];
    }
    *this = transposed;
}

float LinearObject::magnitude()
{
    assertMessage(isVector(this), "Matrix magnitude is not defined, use norm");
    float result = 0;
    for(int i = 0; i < m_NumElements; ++i)
    {
        result += pow(m_pData[i], 2);
    }
    return sqrt(result);
}

float LinearObject::determinant()
{
    assertMessage(m_NumRows == m_NumColumns, "Only square matrices have determinants");
    if(m_NumRows == 2 && m_NumColumns == 2)
    {
        // base case 2x2 matrix det of [a, b;c, d] is ad-bc
        return (m_pData[0] * m_pData[3]) - (m_pData[1] * m_pData[2]);
    }
    return 0;
}

LinearObject LinearObject::inverse()
{
    return LinearObject();
}

float LinearObject::norm(NORM_ORDER order)
{
    if(isVector(this))
    {
        return magnitude();
    }
    switch(order)
    {
        case 1:

            break;
        case 2:

            break;
        case FROB:

            break;
        case INF:

            break;
        case MAX:

            break;
    }
    return -1;
}

void LinearObject::fill()
{
    for(int i = 0; i < m_NumElements; ++i)
    {
        m_pData[i] = static_cast<float>(i);
    }
}

void LinearObject::clear()
{
    for(int i = 0; i < m_NumElements; ++i)
    {
        m_pData[i] = 0;
    }
}




