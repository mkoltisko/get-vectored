
#include "../include/Properties.hpp"

bool isZeroVector(LinearObject* pVector)
{
    for(int i = 0; i < pVector->size(); ++i)
    {
        if((*pVector)[i] != 0)
        {
            return false;
        }
    }
    return true;
}
