
#ifndef PUREERATOSTHENESSIEVE_H
#define PUREERATOSTHENESSIEVE_H

#include "PrimeSieve.h"


class PureEratosthenesSieve : public PrimeSieve
{
    public:
        PureEratosthenesSieve();
        virtual ~PureEratosthenesSieve();

        virtual void Calculate();

    private:
        static unsigned PRIME_DIGITS;
        unsigned* m_allNumbers;
};

#endif
