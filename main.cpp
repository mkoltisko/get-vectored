
#include "SmokeTest/TestExecute.hpp"
#include "SmokeTest/VectorTests/VectorTests.hpp"
#include "SmokeTest/MatrixTests/MatrixTests.hpp"
#include "HelpfulFunctions.hpp"

int main() {

    TestExecute<VectorTests>::Instance()->RunSuite();
    TestExecute<MatrixTests>::Instance()->RunSuite();

    LinearObject mat(4, 4);
    mat[2] = 2;
    mat[4] = 1;
    print(&mat);

    mat.transpose();
    print(&mat);

//    LinearObject matrix(4, 4);
//    SUBSCRIPT s = ind2sub(10, 4, 4);
//    print(s);
//    matrix[s] = 7;
//    print(&matrix);

    return 0;
}
