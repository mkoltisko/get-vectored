
#include "VectorTests.hpp"
#include "../../HelpfulFunctions.hpp"

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
    m_pVecOne = new Vector();
    m_pVecTwo = new Vector();
}

void VectorTests::teardown()
{
    delete m_pVecOne;
    delete m_pVecTwo;
}

void VectorTests::OperatorsTest()
{
    print(m_pVecOne);
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
    print(m_pVecOne);
}

void VectorTests::TransposeTest()
{
    print(m_pVecOne);
}

void VectorTests::MagnitudeTest()
{
    print(m_pVecOne);

}