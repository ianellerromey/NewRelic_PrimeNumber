
#ifndef NAIVESIEVE_H
#define NAIVESIEVE_H

#include "PrimeSieve.h"


class NaiveSieve : public PrimeSieve
{
    public:
        NaiveSieve();
        virtual ~NaiveSieve();

        virtual void Calculate();

    private:
        int m_testNumber;

        bool IsPrime(int number);
};

#endif
