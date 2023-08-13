
#ifndef MAXTRIXTESTS_HPP
#define MAXTRIXTESTS_HPP

#include "../../LinearAlgebra/LinearObject.hpp"
#include "../TestFixture.hpp"

class MatrixTests : public TestFixture
{
public:
    UT_REGISTER_SUITE(MatrixTests)
    UT_REGISTER_TEST(MatrixTests::OperatorsTest)
    UT_REGISTER_TEST(MatrixTests::ProductsTest)
    UT_REGISTER_TEST(MatrixTests::TransposeTest)
    UT_REGISTER_TEST(MatrixTests::PropertiesTest)
    UT_REGISTER_END

    void setup() override;

    void teardown() override;


protected:

    void OperatorsTest();

    void ProductsTest();

    void TransposeTest();

    void PropertiesTest();

private:

    LinearObject* m_pMatOne{};
    LinearObject* m_pMatTwo{};

};


#endif //MAXTRIXTESTS_HPP
