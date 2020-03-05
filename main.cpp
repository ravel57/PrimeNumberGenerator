#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

#define ARRSIZE 0xfffff
#define ROUNDS 10

unsigned long long  arrayOfPrimes[ARRSIZE];
unsigned long long  checkingNumber = 1;
unsigned long long  countOfPrimes = 1;
unsigned long       sq;
unsigned long       localCounter;
bool flagPrime = true;

int timeArr[ROUNDS];
clock_t start, stop, deltaTime;

int main() {
    arrayOfPrimes[0] = 2;
    cout << "start\n" << "count:\t" << ARRSIZE << "\n--------------\n";

    for (int round = 0; round < ROUNDS; round++) {
        start = clock();

        while (countOfPrimes < ARRSIZE) {
            checkingNumber += 2;

            sq = sqrt(checkingNumber), localCounter = 0;
            while (arrayOfPrimes[localCounter] < sq)
                localCounter++;

            for (int i = 1; i <= localCounter; i++) {
                if (checkingNumber % arrayOfPrimes[i] == 0) {
                    flagPrime = false;
                    break;
                }
            }
            if (flagPrime) {
                arrayOfPrimes[countOfPrimes] = checkingNumber;
                countOfPrimes++;
            }
            flagPrime = true;
        }

        stop = clock();
        deltaTime = (stop - start);
        timeArr[round] = deltaTime;
        cout << round << ":\t" << deltaTime << " ms\n";//<< countOfPrimes << endl << checkingNumber << "\n\n";

        checkingNumber = 1; countOfPrimes = 1;
        for (int i = 1; i < ARRSIZE; i++) {
            arrayOfPrimes[i] = 0;
        }
    }

    deltaTime = 0;
    for (int i = 0; i < ROUNDS; i++) {
        deltaTime += timeArr[i];
    }
    cout << "==============\n" << "avg:\t" << deltaTime / ROUNDS << " ms\n";

    cin.get();
    return 0;
}

