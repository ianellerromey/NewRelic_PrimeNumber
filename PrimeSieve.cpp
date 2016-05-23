
#include "PrimeSieve.h"


int PrimeSieve::FIRST_PRIME = 2;


PrimeSieve::PrimeSieve(int currentPrime) :
    m_currentPrime(currentPrime)
{
}


int const PrimeSieve::GetCurrentPrime() const
{
    return m_currentPrime;
}
