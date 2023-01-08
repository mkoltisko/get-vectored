
#include <iostream>
#include <sstream>
#include "../include/Matrix.hpp"
#include "../include/Properties.hpp"


Matrix::Matrix(int rowCount, int colCount)
{
    m_nRows = rowCount;
    m_nCols = colCount;
    m_nElements = m_nRows * m_nCols;
    m_pValues = new int[m_nElements]{};
}

Matrix::~Matrix()
{
    delete[] m_pValues;
}

int& Matrix::at(int x, int y)
{
    return m_pValues[(x-1) * m_nRows + (y-1)];
}

int Matrix::get(int x, int y)
{
    return m_pValues[(x-1) * m_nRows + (y-1)];
}

void Matrix::swap(int x1, int y1, int x2, int y2)
{
    std::swap(this->at(x1, y1), this->at(x2, y2));
}

void Matrix::print()
{
    for(int i = 0; i < m_nElements; ++i)
    {
        std::cout << std::to_string(m_pValues[i]) << ' ';
        if((i+1) % m_nCols == 0)
        {
            std::cout << "\n";
        }
    }
    std::cout << std::endl;
}

std::string Matrix::to_string()
{
    std::stringstream output;
    output << '{';
    for(int i = 0; i < m_nElements; ++i)
    {
        output << std::to_string(m_pValues[i]);
        output << ((i+1) % m_nCols == 0 && i+1 != m_nElements ) ? ", " : "; ";
    }
    output << '}';
    return output.str();
}

void Matrix::transpose()
{
    auto* transposedValues = new int[m_nElements];
    for(int x = 1; x <= m_nCols; ++x)
    {
        for(int y = 1; y <= m_nRows; ++y)
        {
            transposedValues[(y-1) * m_nRows + (x-1)] = this->at(x, y);
        }
    }
    delete [] m_pValues;
    std::swap(m_nRows, m_nCols);
    m_pValues = transposedValues;
}

void Matrix::inverse()
{
    assert(isSquareMatrix(this));   // TODO: pseudo-inverse for non-square matrices

}

float Matrix::determinant()
{
    assert(isSquareMatrix(this));   // TODO: pseudo-determinant for non-square matrices
    return 0;
}

int &Matrix::operator[](int index)
{
    return m_pValues[index];
}

Matrix &Matrix::operator+(Matrix pMatrix)
{
    assert(m_nRows == pMatrix.getRowSize());
    assert(m_nCols == pMatrix.getColSize());
    for(int i = 0; i < m_nElements; ++i)
    {
        m_pValues[i] += pMatrix[i];
    }
    return *this;
}

Matrix &Matrix::operator-(Matrix pMatrix)
{
    assert(m_nRows == pMatrix.getRowSize());
    assert(m_nCols == pMatrix.getColSize());
    for(int i = 0; i < m_nElements; ++i)
    {
        m_pValues[i] -= pMatrix[i];
    }
    return *this;
}

Matrix &Matrix::operator*(Matrix pMatrix)
{
    assert(m_nRows == pMatrix.getRowSize());
    assert(m_nCols == pMatrix.getColSize());
    for(int i = 0; i < m_nElements; ++i)
    {
        m_pValues[i] *= pMatrix[i];
    }
    return *this;
}

void Matrix::insert(int value, uint32_t x, uint32_t y)
{
    assert(x < m_nRows);
    assert(y < m_nCols);
    m_pValues[(x * m_nCols) + y] = value;
}

void Matrix::append(Vector *pVector, DIRECTION direction)
{
    if(direction == TOP || direction == BOTTOM)
    {
        assert(pVector->m_orientation == ROW);
        assert(pVector->size() == m_nCols);
        ++m_nRows;
    }

    if(direction == LEFT || direction == RIGHT)
    {
        assert(pVector->m_orientation == COL);
        assert(pVector->size() == m_nRows);
        ++m_nCols;
    }

    m_nElements = m_nRows * m_nCols;
    int* newValues = new int[m_nElements];

    switch(direction)
    {
        case TOP:

            break;

        case BOTTOM:

            break;

        case LEFT:

            break;

        case RIGHT:

            break;
    }

}



