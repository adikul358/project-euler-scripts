#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <cmath>

using namespace std;

vector<int> ESieve(int upperLimit) {
    int sieveBound = int((upperLimit - 1) / 2);
    int upperSqrt = int((sqrt(upperLimit) - 1) / 2);
 
    vector<bool> primeBits(sieveBound + 1, true);
 
    for (int i = 1; i <= upperSqrt; i++) {
        if (primeBits[i]) {
            for (int j = i * 2 * (i + 1); j <= sieveBound; j += 2 * i + 1) {
                primeBits[j] = false;
            }
        }
    }
 
    vector<int> numbers;
    numbers.push_back(2);
 
    for (int i = 1; i <= sieveBound; i++) {
        if (primeBits[i]) {
            numbers.push_back(2 * i + 1);
        }
    }
 
    return numbers;
}

bool isPrime(int n, vector<int> primes) {
    int i = 0;
    while (primes[i] <= n) {
        if (primes[i] == n) {
            return true;
        }
        i++;
    }
    return false;
}

int main() {
    int aMax = 0, bMax = 0, nMax = 0;
    vector<int> primes = ESieve(87400);
    vector<int> bPos = ESieve(1000);

    for (int a = -999; a < 1001; a +=2) {
        for (int i = 1; i < bPos.size(); i++) {
            for (int j = 0; j < 2; j++) {
                int n = 0;
                int sign = (j == 0) ? 1 : -1; 
                int aodd = (i % 2 == 0) ? -1 : 0;
                while (isPrime(abs(n * n + (a + aodd) * n + sign*bPos[i]), primes)) {
                    n++;
                } 


                if (n > nMax) {
                    printf("Sequence length %d: a = %d, b = %d\n", n, a + aodd, sign*bPos[i]);
                    aMax = a;
                    bMax = bPos[i];
                    nMax = n;
                }
            }
        }
    }
    printf("Max Sequence length %d: a = %d, b = %d\n", nMax, aMax, bMax);
    printf("Product: %d", aMax*bMax);
}