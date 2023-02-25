
#ifndef MATRIX_H_LINEAROBJECT_HPP
#define MATRIX_H_LINEAROBJECT_HPP

#include <string>
#include <sstream>

#include "Properties.hpp"
#include "../HelpfulFunctions.hpp"

enum NORM_ORDER
{
    FROB = 3,
    INF = 4,
    MAX = 5
};


class LinearObject
{
public:

    explicit LinearObject(unsigned int rows = 3, unsigned int cols = 3);
    LinearObject(const LinearObject& obj);
    LinearObject(LinearObject& left, LinearObject& right); // create augmented matrix

    ~LinearObject();

    LinearObject& operator=(const LinearObject& obj);

    float operator[](unsigned int linearIndex) const;
    float& operator[](unsigned int linearIndex);

    float operator[](SUBSCRIPT coords) const;
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
    float at(SUBSCRIPT coord);
    inline unsigned int getNumRows() const { return m_NumRows; }
    inline unsigned int getNumColumns() const { return m_NumColumns; }
    inline unsigned int size() const { return m_NumElements; }
    inline SUBSCRIPT dimensions() const { return SUBSCRIPT(m_NumRows, m_NumColumns); }

    LinearObject getRow(unsigned int i);
    LinearObject getColumn(unsigned int i);


    void fill();
    void clear();
    std::string to_string() const;

    void transpose();
    float magnitude();
    float norm(NORM_ORDER order);
    float determinant();
    LinearObject inverse();

private:

    float* m_pData;
    unsigned int m_NumRows;
    unsigned int m_NumColumns;
    unsigned int m_NumElements;

};

#endif //MATRIX_H_LINEAROBJECT_HPP
