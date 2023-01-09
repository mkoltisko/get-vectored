
#include "SmokeTest/TestExecute.hpp"
#include "SmokeTest/VectorTests/VectorTests.hpp"
#include "SmokeTest/MatrixTests/MatrixTests.hpp"

int main() {

    TestExecute<VectorTests>::Instance()->RunSuite();
    TestExecute<MatrixTests>::Instance()->RunSuite();

    return 0;
}
