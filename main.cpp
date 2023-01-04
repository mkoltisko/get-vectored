
#include <iostream>
#include <string>

#include "include/Vector.hpp"
#include "include/Operations.hpp"

void print(Vector *given) {
    for (int i = 0; i < given->size(); ++i) {
        std::cout << std::to_string(given->at(i)) << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    int values[3]{1, 2, 3};

    Vector first(3);
    Vector second(4);
    Vector third(3);

    first.fill(values);
    third[1] = 1;

    print(&first);
    print(&third);

    std::cout << std::to_string(angle(&first, &third)) << std::endl;

    Matrix firstM;
    firstM.at(2, 2) = 1;
    firstM.at(1, 3) = 1;
    firstM.swap(2, 2, 1, 1);
    firstM.print();
    std::cout << "-----\n";
    firstM.transpose();
    firstM.print();

//    dot(&first, &second);

    return 0;
}
