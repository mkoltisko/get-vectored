
#ifndef TESTEXECUTE_HPP
#define TESTEXECUTE_HPP

template<typename TestSuite>
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
        TestSuite::Instance()->registerTests();

        for(auto& unitTest : *TestSuite::m_TestList)
        {
            TestSuite::Instance()->setup();
            (TestSuite::Instance()->*unitTest)();
            TestSuite::Instance()->teardown();
        }
    }

};

#endif //TESTEXECUTE_HPP
