
#include "PrimeThread.h"
#include "NaiveSieve.h"
#include "PseudoEratosthenesSieve.h"
#include "PureEratosthenesSieve.h"

#include <iostream> // std::cout, std::cin
#include <iomanip> // std::fixed, std::setprecision
#include <ctime> // std::clock
#include <Windows.h> // SetConsoleCursorPosition, etc.


// the NaiveSieve is just for the sake of comparison; it is SIGNIFICANTLY slower than the PseudoEratosthenesSieve
//#define PRIME_SIEVE NaiveSieve
//#define PRIME_SIEVE PseudoEratosthenesSieve
#define PRIME_SIEVE PureEratosthenesSieve

#define CurrentTimeXY 0, 0
#define CurrentPrimeXY 0, 2


void SetCursorXY(int x, int y)
{
    COORD xy = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}


int main()
{
    std::cout << std::fixed << std::setprecision(3);
    auto start = std::clock();
    auto current = start;

    const double maximumDuration = 60;
    double duration = 0;
    int m_lastPrime = 0;

    PRIME_SIEVE sieve;
    PrimeThread thread;
    thread.Start(&sieve);

    do
    {
        SetCursorXY(CurrentTimeXY);
        std::cout << "Current execution duration: " << duration;

        int currentPrime = sieve.GetCurrentPrime();
        if(m_lastPrime != currentPrime)
        {
            m_lastPrime = currentPrime;
            SetCursorXY(CurrentPrimeXY);
            std::cout << "Highest calculated prime: " << m_lastPrime;
        }
        current = std::clock();
    } while((duration = ((double)(current - start) / (double)CLOCKS_PER_SEC)) < maximumDuration);

    // wherever we were when we ran out of time, grab that prime
    m_lastPrime = sieve.GetCurrentPrime();
    
    SetCursorXY(CurrentTimeXY);
    std::cout << "Current execution duration: " << maximumDuration;
    SetCursorXY(CurrentPrimeXY);
    std::cout << "Maximum calculated prime in sixty seconds: " << m_lastPrime << std::endl;

    // we displayed our conclusion before stopping the calculation thread, just in case it takes a little
    // while to close down the thread (it won't, but still)
    thread.Stop();

    std::cout << "Press any key to quit ...";
    std::cin.get();
}