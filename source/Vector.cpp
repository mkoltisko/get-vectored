//
// Created by User on 6/11/2022.
//

#include <sstream>
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

int& Vector::operator[](uint32_t index)
{
    assert(index < m_length);
    return m_pData[index];
}

int Vector::get(unsigned int index)
{
    assert(index < m_length);
    return m_pData[index];
}

void Vector::set(unsigned int index, int value)
{
    assert(index < m_length);
    m_pData[index] = value;
}

void Vector::fill(const int* newValues, unsigned int length)
{
    assert(length <= m_length);
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
        m_pData[i] += pGiven.get(i);
    }
    return *this;
}

std::string Vector::to_string() const {
    std::stringstream ss;
    for(int i = 0; i < size(); ++i)
    {
        ss << m_pData[i];
    }
    return ss.str();
}
