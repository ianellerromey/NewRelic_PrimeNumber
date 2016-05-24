
#include "PureEratosthenesSieve.h"

#include <cstdlib> // calloc
#include <cstring> // memset


// after repeated testing, this number seems likely to get me the hightest value; i.e., walking doesn't take too long
unsigned PureEratosthenesSieve::PRIME_DIGITS = 1325000000;


PureEratosthenesSieve::PureEratosthenesSieve() :
    PrimeSieve(FIRST_PRIME)
{
    m_allNumbers = (unsigned*)calloc(PRIME_DIGITS, sizeof(unsigned));
    // leave the zero, one, and two indices initialized to 0;
    // set everything else to 1
    memset(m_allNumbers + 3, 1, sizeof(unsigned) * PRIME_DIGITS);
}


PureEratosthenesSieve::~PureEratosthenesSieve()
{
    if(m_allNumbers)
    {
        free(m_allNumbers);
        m_allNumbers = NULL;
    }
}


void PureEratosthenesSieve::Calculate()
{
    // all multiples of our current prime number are not prime numbers
    for(auto incr = m_currentPrime; incr < PRIME_DIGITS; incr += m_currentPrime)
    {
        m_allNumbers[incr] = 0;
    }

    // walk our current prime forward, past all the multiples of other primes,
    // until we find a new one
    auto nextPrime = m_currentPrime;
    while(nextPrime < PRIME_DIGITS && m_allNumbers[nextPrime] == 0) 
    {
        ++nextPrime;
    }

    // only grab the next prime number if we didn't walk all the way to the end
    if(nextPrime != PRIME_DIGITS)
    {
        m_currentPrime = nextPrime;
    }

    m_allNumbers[m_currentPrime] = 0;
}
