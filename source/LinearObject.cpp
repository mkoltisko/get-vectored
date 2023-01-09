
#include "LinearObject.hpp"


LinearObject::LinearObject(unsigned int rows, unsigned int cols) {

}

LinearObject::LinearObject(LinearObject *first, LinearObject &second) {

}

LinearObject::~LinearObject() {

}

int& LinearObject::operator[](unsigned int linearIndex) {
    return m_pData[linearIndex];
}

int &LinearObject::operator()(unsigned int x, unsigned int y) {
    return m_pData[(x-1) * m_NumRows + (y-1)];
}

LinearObject LinearObject::operator+(unsigned int scalar) {
    return LinearObject();
}

LinearObject LinearObject::operator+(LinearObject &other) {
    return LinearObject();
}

LinearObject LinearObject::operator-(unsigned int scalar) {
    return LinearObject();
}

LinearObject LinearObject::operator-(LinearObject &other) {
    return LinearObject();
}

LinearObject LinearObject::operator*(unsigned int scalar) {
    return LinearObject();
}

LinearObject LinearObject::operator*(LinearObject &other) {
    return LinearObject();
}

LinearObject LinearObject::operator/(unsigned int scalar) {
    return LinearObject();
}

LinearObject LinearObject::operator/(LinearObject &other) {
    return LinearObject();
}

int LinearObject::get(unsigned int index) {
    return 0;
}

std::string LinearObject::to_string() const {
    return std::string();
}

void LinearObject::transpose() {

}

float LinearObject::magnitude() {
    return 0;
}

float LinearObject::determinant() {
    return 0;
}

LinearObject LinearObject::inverse() {
    return LinearObject();
}
