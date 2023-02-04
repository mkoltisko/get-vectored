
#include "SmokeTest/TestExecute.hpp"
#include "SmokeTest/VectorTests/VectorTests.hpp"
#include "SmokeTest/MatrixTests/MatrixTests.hpp"
#include "HelpfulFunctions.hpp"

int main() {

    TestExecute<VectorTests>::Instance()->RunSuite();
    TestExecute<MatrixTests>::Instance()->RunSuite();

    LinearObject matR(3, 3);
    matR[SUBSCRIPT(2, 1)] = 2;
    matR[4] = 1;
    print(matR);

    LinearObject matL(3, 1);
    matL[0] = 3;
    matL[1] = 7;
    print(matL);

    LinearObject A(matR, matL);
    print(A);

//    LinearObject prod = matR * matL;
//    print(prod);
//
//    print(Identity(5));

//    LinearObject m1(4, 3);
//    m1.fill();
//    print(m1);
//
//    m1.clear();
//    for(int y = 0; y < m1.getNumColumns(); ++y)
//    {
//        for(int x = 0; x < m1.getNumRows(); ++x)
//        {
//            m1(x, y) = sub2ind(SUBSCRIPT(x, y), m1);
//        }
//    }
//    print(m1);
//
//    m1.clear();
//    for(int i = 0; i < m1.size(); ++i)
//    {
//        m1[i] = sub2ind(ind2sub(i, m1), m1);
//    }
//    print(m1);
//
//    print(m1.getRow(2));
//    print(m1.getColumn(2));
//
//    m1.transpose();
//    print(m1);
    //    LinearObject matrix(4, 4);
//    SUBSCRIPT s = ind2sub(10, 4, 4);
//    print(s);
//    matrix[s] = 7;
//    print(&matrix);

    return 0;
}
