
#ifndef PRIMESIEVE_H
#define PRIMESIEVE_H

class PrimeSieve
{
    public:
        PrimeSieve(int currentPrime);
        virtual ~PrimeSieve();

        virtual void Calculate() = 0;
        virtual int const GetCurrentPrime() const;

    protected:
        static int FIRST_PRIME;
        int m_currentPrime;
};

#endif
