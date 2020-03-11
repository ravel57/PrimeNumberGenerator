#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>
using namespace std;

#define ARRSIZE 0x3ffffff
#define ROUNDS 1

unsigned long long  arrayOfPrimes[ARRSIZE];
unsigned long long  checkingNumber;
unsigned long long  countOfPrimes;
unsigned long       localCounter;
double              sq;
//bool flagPrime = true;

int timeArr[ROUNDS];
clock_t start, stop, deltaTime;

ofstream file("pn.txt", ios::trunc);


inline void clc() {
    for (int i = 0; i < localCounter; i++)
        if (checkingNumber % arrayOfPrimes[i] == 0)
            return;
    arrayOfPrimes[countOfPrimes++] = checkingNumber;
//    countOfPrimes++;
    if (countOfPrimes % 100 == 0) {
        file << checkingNumber << "\t:\t" << clock() - start << "\tmks\n";
    }
}

int main() {
    arrayOfPrimes[0] = 3;
    cout << "start\n" << "count:\t" << ARRSIZE << "\n--------------\n";

    for (int round = 0; round < ROUNDS; round++) {
        start = clock();

        for (checkingNumber = 5, countOfPrimes = 1; countOfPrimes < ARRSIZE; checkingNumber += 2) {
            sq = sqrt(checkingNumber), localCounter = 0;
            while (arrayOfPrimes[localCounter] <= sq)
                localCounter++;

            clc();
            /*for (int i = 1; i <= localCounter; i++) {
                if (checkingNumber % arrayOfPrimes[i] == 0) {
                    flagPrime = false;
                    break;
                }
            }
            if (flagPrime) {
                arrayOfPrimes[countOfPrimes] = checkingNumber;
                countOfPrimes++;
            }
            flagPrime = true;*/
        }

///     linux
        stop = clock();
        deltaTime = (stop - start)/1000;
        timeArr[round] = deltaTime;
        cout << round << ":\t\t" << deltaTime << " ms\n";

////       windows
//        deltaTime = stop - start;
//        timeArr[round] = deltaTime;
//        cout << round << ":\t" << deltaTime << " ms\n";

        for (int i = 1; i < ARRSIZE; i++) {
            arrayOfPrimes[i] = 0;
        }
        file << "\n";
        file.close();
    }

    deltaTime = 0;
    for (int round : timeArr) {
        deltaTime += round;
    }
    cout << "==============\n" << "avg:\t" << deltaTime / ROUNDS << " ms\n";

    cin.get();
    return 0;
}

