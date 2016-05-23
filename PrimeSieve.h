
#ifndef PRIMESIEVE_H
#define PRIMESIEVE_H

class PrimeSieve
{
    public:
        PrimeSieve(int currentPrime);
        virtual void Calculate() = 0;
        virtual int const GetCurrentPrime() const;

    protected:
        int m_currentPrime;
};

#endif
