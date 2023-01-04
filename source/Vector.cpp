//
// Created by User on 6/11/2022.
//

#include "../include/Vector.hpp"
#include "../include/Properties.hpp"
#include "../include/Operations.hpp"

Vector::Vector(int size, bool orientation) :
    m_length(size),
    m_orientation(orientation)
{
    m_pData = new int[size]{};
}

Vector::~Vector()
{
    delete[] m_pData;
    m_pData = nullptr;
}

int& Vector::operator[](int index)
{
    assert(index > -1 && index < m_length);
    return m_pData[index];
}

int Vector::at(int index)
{
    assert(index > -1 && index < m_length);
    return m_pData[index];
}

void Vector::fill(const int* newValues)
{
    for(int i = 0; i < size(); ++i)
    {
        m_pData[i] = newValues[i];
    }
}

void Vector::transpose()
{
    m_orientation = !m_orientation;
}

float Vector::magnitude()
{
    return sqrt(dot(this, this));
}

Vector& Vector::operator+(Vector pGiven) {
    assert(this->size() == pGiven.size());
    for(int i = 0; i < this->size(); ++i)
    {
        m_pData[i] += pGiven.at(i);
    }
    return *this;
}
