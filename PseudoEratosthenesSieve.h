
#ifndef PSEUDOERATOSTHENESSIEVE_H
#define PSEUDOERATOSTHENESSIEVE_H

#include "PrimeSieve.h"


class PseudoEratosthenesSieve : public PrimeSieve
{
    public:
        PseudoEratosthenesSieve();

        virtual void Calculate();

    private:
        static int PRIME_DIGITS;
        int* m_allNumbers;
        int* m_previousPrimes;
        int* m_previousPrimesLastIndex;
};

#endif
