
#include <iostream>
#include <string>

#include "include/Vector.hpp"
#include "include/Operations.hpp"

#include "SmokeTest/VectorTests/VectorTests.hpp"
#include "SmokeTest/TestExecute.hpp"

int main() {
    std::cout << "Hello, World!" << std::endl;

    TestExecute::Instance()->RunSuite();

    return 0;
}
