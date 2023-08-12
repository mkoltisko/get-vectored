
#ifndef TESTFIXTURE_HPP
#define TESTFIXTURE_HPP

#include <vector>
#include "../HelpfulFunctions.hpp"

// macro for singleton-ness and start test register
#define UT_REGISTER_SUITE(suiteName)    \
    static suiteName* Instance()        \
    {                                   \
        static suiteName objTests;      \
        return &objTests;               \
    }                                   \
    inline void registerTests() {                         

// macro for adding test to list
#define UT_REGISTER_TEST(testName)  \
    m_TestList->push_back(static_cast<UnitTest>(&testName));

// macro to close inline function created by first macro
#define UT_REGISTER_END }

class TestFixture
{
public:

    // specific type for member functions taking nothing and returning nothing
    typedef void (TestFixture::*UnitTest)();
    static std::vector<TestFixture::UnitTest>* m_TestList;

    virtual void registerTests() = 0;

    virtual void setup() = 0;

    virtual void teardown() = 0;

protected:

    TestFixture() {}

    ~TestFixture() {}

    TestFixture(const TestFixture&) {};             // inaccessible
    TestFixture& operator=(const TestFixture&) {};  // inaccessible

private:


};

#endif //TESTFIXTURE_HPP
