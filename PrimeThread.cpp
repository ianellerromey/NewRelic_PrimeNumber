
#include "PrimeThread.h"


void Calculate(PrimeSieve* const sieve, PrimeThread* const thread)
{
    while(thread->IsGoing())
    {
        sieve->Calculate();
    }
}


PrimeThread::PrimeThread() :
    m_primeSieve(0),
    m_go(false)
{
}


void PrimeThread::Start(PrimeSieve* const sieve)
{
    m_go = true;
    m_primeSieve = sieve;
    m_thread = std::thread(Calculate, m_primeSieve, this);
}


void PrimeThread::Stop()
{
    m_go = false;
    m_thread.join();
}


bool const PrimeThread::IsGoing() const
{
    return m_go;
}