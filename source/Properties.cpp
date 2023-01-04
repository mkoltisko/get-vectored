//
// Created by User on 6/9/2022.
//

#include "include/Properties.hpp"

bool isZeroVector(Vector* pVector)
{
    for(int i = 0; i < pVector->size(); ++i)
    {
        if(pVector->at(i) != 0)
        {
            return false;
        }
    }
    return true;
}

bool isSquareMatrix(Matrix* pMatrix)
{
    return pMatrix->getRowSize() == pMatrix->getColSize();
}
