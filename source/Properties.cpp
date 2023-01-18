
#include "../include/Properties.hpp"


bool isVector(LinearObject *pVector)
{

    return pVector->getNumRows() == 1 ^ pVector->getNumColumns() == 1;
}

bool isZeroVector(LinearObject* pVector)
{
    if(!isVector(pVector))
    {
        return false;
    }

    for(int i = 0; i < pVector->size(); ++i)
    {
        if(pVector->at(i) != 0)
        {
            return false;
        }
    }
    return true;
}

bool isColumnVector(LinearObject *pVector)
{
    return isVector(pVector) && pVector->getNumColumns() == 1;
}

bool isRowVector(LinearObject *pVector)
{
    return isVector(pVector) && pVector->getNumRows() == 1;
}

bool isSquareMatrix(LinearObject *pMatrix)
{
    return pMatrix->getNumRows() == pMatrix->getNumColumns();
}

bool isSymmetrical(LinearObject *pMatrix)
{
    if(!isSquareMatrix(pMatrix))
    {
        return false;
    }
    for(int i = 0; i < pMatrix->size(); ++i)
    {
        if(pMatrix->at(i) != pMatrix->at(pMatrix->size() - i+1))
        {
            return false;
        }
    }
    return true;
}

bool isInvertible(LinearObject *pMatrix)
{
    if(!isSquareMatrix(pMatrix))
    {
        return false;
    }
    //
    return false;
}
