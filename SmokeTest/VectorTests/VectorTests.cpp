
#include "VectorTests.hpp"

std::vector<VectorTests::UnitTest>* VectorTests::m_TestList = nullptr;

void VectorTests::registerTests()
{
    if(m_TestList != nullptr)
    {
        return;
    }

    m_TestList = new std::vector<VectorTests::UnitTest>();
    m_TestList->push_back(&VectorTests::OperatorsTest);
    m_TestList->push_back(&VectorTests::ProductsTest);
    m_TestList->push_back(&VectorTests::TransposeTest);
    m_TestList->push_back(&VectorTests::MagnitudeTest);
}


void VectorTests::setup()
{
    m_pVecOne = new LinearObject();
    m_pVecTwo = new LinearObject();
}

void VectorTests::teardown()
{
    delete m_pVecOne;
    delete m_pVecTwo;
}

void VectorTests::OperatorsTest()
{
    print("Vector Test 1 called");
//    m_pVecOne->set(0, 1);
//    m_pVecTwo->set(2, 1);
//
//    Vector sum = *m_pVecOne + *m_pVecTwo;
//
//    AssertMessage(sum.get(0) == 1, "Vector Addition no work");
//    AssertMessage(sum.get(2) == 1, "Vector Addition no work");

}

void VectorTests::ProductsTest()
{
    print("Vector Test 2 called");
}

void VectorTests::TransposeTest()
{
    print("Vector Test 3 called");
}

void VectorTests::MagnitudeTest()
{
    print("Vector Test 4 called");

}