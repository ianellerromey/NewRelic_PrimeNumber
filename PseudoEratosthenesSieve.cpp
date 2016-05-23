
#include "PseudoEratosthenesSieve.h"

#include <cstdlib> // calloc
#include <cstring> // memset


int PseudoEratosthenesSieve::PRIME_DIGITS = 100000000;


PseudoEratosthenesSieve::PseudoEratosthenesSieve() :
    PrimeSieve(2)
{
        m_allNumbers = (int*)calloc(PRIME_DIGITS, sizeof(int));
        // leave the zero, one, and two indices initialized to 0;
        // set everything else to 1
        memset(m_allNumbers + 3, 1, sizeof(int) * PRIME_DIGITS);

        m_previousPrimes = (int*)calloc(PRIME_DIGITS, sizeof(int));
        m_previousPrimesLastIndex = (int*)calloc(PRIME_DIGITS, sizeof(int));

        m_previousPrimes[0] = m_currentPrime;
        m_previousPrimesLastIndex[0] = m_currentPrime;
}


void PseudoEratosthenesSieve::Calculate()
{
    int i = 0;
    // for every known prime ...
    do
    {
        auto prime = m_previousPrimes[i];
        // ... calculate at least x multiples of it, where x is our current prime;
        // this is a little arbitrary, but will keep us from accidentally walking into a non-prime
        for(int start = 0; start < m_currentPrime; ++start)
        {
            auto primeIndex = m_previousPrimesLastIndex[i] + prime;
            if(primeIndex > PRIME_DIGITS)
                break;

            m_allNumbers[primeIndex] = 0;
            m_previousPrimesLastIndex[i] = primeIndex;
        }
        ++i;
    } while(m_previousPrimes[i] != 0 && i < PRIME_DIGITS);

    // walk our current prime forward, past all the multiples of other primes,
    // until we find a new one
    while(m_allNumbers[m_currentPrime] == 0) 
    {
        ++m_currentPrime;
    }

    m_allNumbers[m_currentPrime] = 0;
    m_previousPrimes[i] = m_currentPrime;
    m_previousPrimesLastIndex[i] = m_currentPrime;
}
