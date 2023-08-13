
#include "LinkedListTests.hpp"

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
    assert(m_pList->length() == 0);

    float a = 13.2;
    float b = 0.7;
    float c = 765.1;
    float d = 934.0;

    m_pList->push(a);
    m_pList->push(b);
    assert(m_pList->length() == 2);
    assert(m_pList->get(0) == (float)0.7);
    assert(m_pList->get(1) == (float)13.2);

    m_pList->push_back(c);
    assert(m_pList->length() == 3);
    assert(m_pList->get(2) == (float)765.1);

    m_pList->insert(1, d);
    assert(m_pList->length() == 4);
    assert(m_pList->get(1) == (float)934.0);

    print(m_pList->to_string());

}

void LinkedListTests::RemoveTest()
{
    print("List Test 2 called");
}

void LinkedListTests::PrintTest()
{
    print("List Test 4 called");
}
