
#ifndef PRIMETHREAD_H
#define PRIMETHREAD_H

#include "PrimeSieve.h"

#include <thread>


class PrimeThread
{
    public:
        PrimeThread();

        void Start(PrimeSieve* const primeSieve);
        void Stop();

        bool const IsGoing() const;

    private:
        PrimeSieve* m_primeSieve;
        std::thread m_thread;

        bool m_go;
};

#endif
