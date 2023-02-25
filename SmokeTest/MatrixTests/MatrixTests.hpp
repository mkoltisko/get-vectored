
#ifndef MAXTRIXTESTS_HPP
#define MAXTRIXTESTS_HPP


#include <vector>
#include "../../LinearAlgebra/LinearObject.hpp"
#include "../TestFixture.hpp"


class MatrixTests : public TestFixture
{
public:

    // specific type for member functions taking nothing and returning nothing
    typedef void (MatrixTests::*UnitTest)();
    static std::vector<MatrixTests::UnitTest>* m_TestList;

    static MatrixTests* Instance()
    {
        static MatrixTests objVectorTests;
        return &objVectorTests;
    }

    void registerTests() override;

    void setup() override;

    void teardown() override;


protected:

    void OperatorsTest();

    void ProductsTest();

    void TransposeTest();

    void PropertiesTest();

private:

    MatrixTests() = default;

    LinearObject* m_pMatOne{};
    LinearObject* m_pMatTwo{};

};


#endif //MATRIX_H_MAXTRIXTESTS_HPP
