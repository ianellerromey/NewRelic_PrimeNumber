
#include "NaiveSieve.h"


NaiveSieve::NaiveSieve() :
    PrimeSieve(FIRST_PRIME),
    m_testNumber(FIRST_PRIME)
{
}


NaiveSieve::~NaiveSieve()
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
