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

int main() {}