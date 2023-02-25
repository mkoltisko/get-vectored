
#include "MatrixTests.hpp"

std::vector<MatrixTests::UnitTest>* MatrixTests::m_TestList = nullptr;

void MatrixTests::registerTests()
{
    if(m_TestList != nullptr)
    {
        return;
    }

    m_TestList = new std::vector<MatrixTests::UnitTest>();
    m_TestList->push_back(&MatrixTests::OperatorsTest);
    m_TestList->push_back(&MatrixTests::ProductsTest);
    m_TestList->push_back(&MatrixTests::TransposeTest);
    m_TestList->push_back(&MatrixTests::PropertiesTest);
}

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
