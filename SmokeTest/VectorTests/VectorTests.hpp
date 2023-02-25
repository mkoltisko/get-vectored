
#ifndef VECTORTESTS_HPP
#define VECTORTESTS_HPP

#include <vector>
#include "../../LinearAlgebra/LinearObject.hpp"
#include "../TestFixture.hpp"


class VectorTests : public TestFixture
{
public:

    // specific type for member functions taking nothing and returning nothing
    typedef void (VectorTests::*UnitTest)();
    static std::vector<VectorTests::UnitTest>* m_TestList;

    static VectorTests* Instance()
    {
        static VectorTests objVectorTests;
        return &objVectorTests;
    }

    void registerTests() override;

    void setup() override;

    void teardown() override;

protected:

    void OperatorsTest();

    void ProductsTest();

    void TransposeTest();

    void MagnitudeTest();

private:

    VectorTests() = default;

    LinearObject* m_pVecOne{};
    LinearObject* m_pVecTwo{};
};


#endif //MATRIX_H_VECTORTESTS_HPP
