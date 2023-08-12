
#include "LinkedListTests.hpp"

// void LinkedListTests::registerTests()
// {
//     m_TestList->push_back(static_cast<UnitTest>(&LinkedListTests::AddTest));
//     m_TestList->push_back(static_cast<UnitTest>(&LinkedListTests::RemoveTest));
//     m_TestList->push_back(static_cast<UnitTest>(&LinkedListTests::PrintTest));
// }

void LinkedListTests::setup()
{
    m_pList = new LinkedList<float>();
}

void LinkedListTests::teardown()
{
    delete m_pList;
}

void LinkedListTests::AddTest()
{
    print("List Test 1 called");
}

void LinkedListTests::RemoveTest()
{
    print("List Test 2 called");
}

void LinkedListTests::PrintTest()
{
    print("List Test 4 called");
}
