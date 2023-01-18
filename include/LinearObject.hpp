
#ifndef MATRIX_H_LINEAROBJECT_HPP
#define MATRIX_H_LINEAROBJECT_HPP

#include <string>
#include <sstream>

#include "Properties.hpp"
#include "../HelpfulFunctions.hpp"

class LinearObject
{
public:

    explicit LinearObject(unsigned int rows = 3, unsigned int cols = 3);
    LinearObject(LinearObject* first, LinearObject* second); // create augmented matrix

    ~LinearObject();

    float& operator[](unsigned int linearIndex);
    float& operator[](SUBSCRIPT coords);

    float& operator()(unsigned int x, unsigned int y);

    LinearObject operator+(float scalar);
    LinearObject operator+(LinearObject& other);

    LinearObject operator-(float scalar);
    LinearObject operator-(LinearObject& other);

    LinearObject operator*(float scalar);
    LinearObject operator*(LinearObject& other);

    LinearObject operator/(float scalar);
    LinearObject operator/(LinearObject& other);

    float at(unsigned int index);
    inline int getNumRows() const { return m_NumRows; }
    inline int getNumColumns() const { return m_NumColumns; }
    inline int size() const { return m_NumElements; }
    inline bool empty() const { return m_NumElements == 0; }

    inline SUBSCRIPT dimensions() const {
        return SUBSCRIPT(m_NumRows, m_NumColumns);
    }

    std::string to_string() const;

    void transpose();
    float magnitude();
    float determinant();
    LinearObject inverse();

private:

    float* m_pData;
    unsigned int m_NumRows;
    unsigned int m_NumColumns;
    unsigned int m_NumElements;

};

#endif //MATRIX_H_LINEAROBJECT_HPP
