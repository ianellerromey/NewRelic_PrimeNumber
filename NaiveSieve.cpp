
#include "NaiveSieve.h"


NaiveSieve::NaiveSieve() :
    PrimeSieve(2),
    m_testNumber(2)
{
}


void NaiveSieve::Calculate()
{
    ++m_testNumber;
    if(IsPrime(m_testNumber))
        m_currentPrime = m_testNumber;
}


bool NaiveSieve::IsPrime(int number)
{
    for(int i = number - 1; i > 1; --i)
    {
        if(number % i == 0)
            return false;
    }

    return true;
}
