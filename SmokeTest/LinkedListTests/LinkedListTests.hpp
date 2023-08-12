
#ifndef LINKEDLISTTESTS_HPP
#define LINKEDLISTTESTS_HPP

#include "../../DataStructures/LinkedList.hpp"
#include "../TestFixture.hpp"

class LinkedListTests : public TestFixture
{
public:
    UT_REGISTER_SUITE(LinkedListTests)
    UT_REGISTER_TEST(LinkedListTests::AddTest)
    UT_REGISTER_TEST(LinkedListTests::RemoveTest)
    UT_REGISTER_TEST(LinkedListTests::PrintTest)
    UT_REGISTER_END

    // void registerTests() override;

    void setup() override;

    void teardown() override;

protected:

    void AddTest();

    void RemoveTest();

    void PrintTest();

private:

    LinkedListTests() = default;

    LinkedList<float>* m_pList{};
};


#endif //LINKEDLISTTESTS_HPP
