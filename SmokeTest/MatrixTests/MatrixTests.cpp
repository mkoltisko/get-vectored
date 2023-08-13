
#include "MatrixTests.hpp"

void MatrixTests::setup()
{
    m_pMatOne = new LinearObject();
    m_pMatTwo = new LinearObject();
}

void MatrixTests::teardown()
{
    delete m_pMatOne;
    delete m_pMatTwo;
}

void MatrixTests::OperatorsTest()
{
    print("Matrix Test 1 called");
}

void MatrixTests::ProductsTest()
{
    print("Matrix Test 2 called");

}

void MatrixTests::TransposeTest()
{
    print("Matrix Test 3 called");

}

void MatrixTests::PropertiesTest()
{
    print("Matrix Test 4 called");

}
