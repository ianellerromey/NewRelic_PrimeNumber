
#include "PrimeSieve.h"


PrimeSieve::PrimeSieve(int currentPrime) :
    m_currentPrime(currentPrime)
{
}


int const PrimeSieve::GetCurrentPrime() const
{
    return m_currentPrime;
}
