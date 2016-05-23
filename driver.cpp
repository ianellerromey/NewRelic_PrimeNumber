
#include <climits>
#include <iostream>
#include <thread>
#include <ctime>

#define PRIME_DIGITS 100000000

/*struct AllNumbers
{
    AllNumbers() :
        m_currentPrime(2)
    {
        m_allNumbers = (int*)malloc(sizeof(int) * PRIME_DIGITS);
        m_previousPrimes = (int*)malloc(sizeof(int) * PRIME_DIGITS);
        m_previousPrimesLastIndex = (int*)malloc(sizeof(int) * PRIME_DIGITS);

        memset(m_allNumbers, 1, sizeof(int) * PRIME_DIGITS);
        memset(m_previousPrimes, 0, sizeof(int) * PRIME_DIGITS);
        memset(m_previousPrimesLastIndex, 0, sizeof(int) * PRIME_DIGITS);

        memset(m_allNumbers, 0, sizeof(int) * 3);
        m_previousPrimes[0] = m_currentPrime;
        m_previousPrimesLastIndex[0] = m_currentPrime;
    }

    void Calculate()
    {
        int i = 0;
        do
        {
            auto prime = m_previousPrimes[i];
            for(int start = 0, end = prime; start < end; ++start)
            {
                auto primeIndex = m_previousPrimesLastIndex[i] + prime;
                if(primeIndex > PRIME_DIGITS)
                    break;
                m_allNumbers[primeIndex] = 0;
                m_previousPrimesLastIndex[i] = primeIndex;
            }
            ++i;
        } while(m_previousPrimes[i] != 0 && i < PRIME_DIGITS);

        while(m_allNumbers[m_currentPrime] == 0) 
        {
            ++m_currentPrime;
        }

        m_allNumbers[m_currentPrime] = 0;
        m_previousPrimes[i] = m_currentPrime;
        m_previousPrimesLastIndex[i] = m_currentPrime;
    }

    int m_currentPrime;
    int* m_allNumbers;
    int* m_previousPrimes;
    int* m_previousPrimesLastIndex;
};*/

/**/struct AllNumbers
{
    AllNumbers() :
        m_currentPrime(2),
        m_testNumber(2)
    {
    }

    bool IsPrime(int number)
    {
        for(int i = number - 1; i > 1; --i)
        {
            if(number % i == 0)
                return false;
        }

        return true;
    }

    void Calculate()
    {
        ++m_testNumber;
        if(IsPrime(m_testNumber))
            m_currentPrime = m_testNumber;
    }

    int m_currentPrime;
    int m_testNumber;
};/**/

void calc(AllNumbers* a)
{
    while(true)
    {
        a->Calculate();
    }
}

int main()
{
    auto start = std::clock();
    auto current = start;

    AllNumbers a;
    int m_lastPrime = 0;
    std::thread t(calc, &a);

    bool go = true;
    while(go)
    {
        auto clock = std::clock();
        if(((clock - start) / (double)CLOCKS_PER_SEC) >= 60)
        {
            go = false;
        }
        else if(((std::clock() - current) / (double)CLOCKS_PER_SEC) >= 1)
        {
            current = std::clock();
            if(m_lastPrime != a.m_currentPrime != m_lastPrime)
            {
                m_lastPrime = a.m_currentPrime;
                std::cout << m_lastPrime << "\r\n";
            }
        }
    }

    std::cout << "Maximum calculated prime in sixty seconds: " << m_lastPrime;
}