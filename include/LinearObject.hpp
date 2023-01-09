
#ifndef MATRIX_H_LINEAROBJECT_HPP
#define MATRIX_H_LINEAROBJECT_HPP

#include <string>


class LinearObject
{
public:

    LinearObject(unsigned int rows = 3, unsigned int cols = 3);
    LinearObject(LinearObject* first, LinearObject& second); // create augmented matrix

    ~LinearObject();

    int& operator[](unsigned int linearIndex);

    int& operator()(unsigned int x, unsigned int y);

    LinearObject operator+(unsigned int scalar);
    LinearObject operator+(LinearObject& other);

    LinearObject operator-(unsigned int scalar);
    LinearObject operator-(LinearObject& other);

    LinearObject operator*(unsigned int scalar);
    LinearObject operator*(LinearObject& other);

    LinearObject operator/(unsigned int scalar);
    LinearObject operator/(LinearObject& other);

    int get(unsigned int index);
    int getNumRows() const { return m_NumRows; }
    int getNumColumns() const { return m_NumColumns; }
    int size() const { return m_NumElements; }
    bool empty() const { return m_NumElements == 0; }

    std::string to_string() const;

    void transpose();
    float magnitude();
    float determinant();
    LinearObject inverse();

protected:

    int* m_pData;
    int m_NumColumns;
    int m_NumRows;
    int m_NumElements;

};

#endif //MATRIX_H_LINEAROBJECT_HPP
