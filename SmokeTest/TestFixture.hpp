
#ifndef TESTFIXTURE_HPP
#define TESTFIXTURE_HPP


#include "../HelpfulFunctions.hpp"

class TestFixture
{
public:

    virtual void registerTests() = 0;

    virtual void setup() = 0;

    virtual void teardown() = 0;

protected:

    TestFixture() {}  // make `protected` for further inheritance
    TestFixture(const TestFixture&) {};             // inaccessible
    TestFixture& operator=(const TestFixture&) {};  // inaccessible

private:


};

#endif //TESTFIXTURE_HPP
