
#ifndef VECTORTESTS_HPP
#define VECTORTESTS_HPP

#include "../../LinearAlgebra/LinearObject.hpp"
#include "../TestFixture.hpp"

class VectorTests : public TestFixture
{
public:
    UT_REGISTER_SUITE(VectorTests)
    UT_REGISTER_TEST(VectorTests::OperatorsTest)
    UT_REGISTER_TEST(VectorTests::ProductsTest)
    UT_REGISTER_TEST(VectorTests::TransposeTest)
    UT_REGISTER_TEST(VectorTests::MagnitudeTest)
    UT_REGISTER_END
    
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


#endif //VECTORTESTS_HPP
