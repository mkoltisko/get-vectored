
#ifndef MATRIX_H_HELPFULFUNCTIONS_HPP
#define MATRIX_H_HELPFULFUNCTIONS_HPP

#include <iostream>
#include <cassert>

#include <LinearObject.hpp>


void print(const std::string& message);
void print(const LinearObject* matrix);
void assertMessage(bool condition, const std::string& message = "");



#endif //MATRIX_H_HELPFULFUNCTIONS_HPP
