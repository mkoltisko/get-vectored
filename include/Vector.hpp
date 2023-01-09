
#ifndef LINEARALGEBRA_VECTOR_HPP
#define LINEARALGEBRA_VECTOR_HPP

#include <string>
#include <vector>
#include <cassert>

enum ORIENTATION
{
    COL = true,
    ROW = false,
};


class Vector {
public:

    explicit Vector(int size = 3, bool orientation = ORIENTATION::COL);

    ~Vector();

    bool m_orientation;

    std::string to_string() const;

    int& operator[](uint32_t index);
    Vector& operator+(Vector pGiven);
    Vector& operator-(Vector pGiven);
    Vector& operator*(Vector pGiven);

    int get(unsigned int index);
    void set(unsigned int index, int value);
    void fill(const int* newValues, unsigned int length);

    void transpose();
    float magnitude();

    inline int size() const { return m_length; }

private:

    int* m_pData;
    int m_length;
};


#endif //LINEARALGEBRA_VECTOR_HPP
