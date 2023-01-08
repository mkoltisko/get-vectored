
#ifndef TESTEXECUTE_HPP
#define TESTEXECUTE_HPP

#include "TestFixture.hpp"
#include "VectorTests/VectorTests.hpp"

class TestExecute
{
public:

    static TestExecute* Instance()
    {
        static TestExecute objTestExecutor;
        return &objTestExecutor;
    }

    inline void RunSuite()
    {
        VectorTests::Instance()->registerTests();

        for(auto& unitTest : *VectorTests::m_TestList)
        {
            VectorTests::Instance()->setup();
            (VectorTests::Instance()->*unitTest)();
            VectorTests::Instance()->teardown();
        }
    }

};

#endif //TESTEXECUTE_HPP
