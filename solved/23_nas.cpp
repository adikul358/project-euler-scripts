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


int sumOfFactors(int n, vector<int> primeList) {
    int number = n;
    int sum = 1;
    int p = primeList[0];
    int j;
    int i = 0;
 
    while (p * p <= n && n > 1 && i < primeList.size()) { 
        p = primeList[i]; i++; 
        if (n % p == 0) { 
            j = p * p; 
            n = n / p; 
            while (n % p == 0) { 
                j = j * p; 
                n = n / p; 
            } 
            sum = sum * (j - 1) / (p - 1); 
        } 
    }
    if (n > 1) {
        sum *= n + 1;
    }
    return sum - number;
}

int main() {
    vector<int> abundent;
    int limit = 28123;
    int sum = 0;
    vector<int> primeList = ESieve(int(sqrt(limit)));

    for (int i = 2; i < limit; i++) {
        int a = sumOfFactors(i, primeList);
        if (a > i) {
            abundent.push_back(i);
        }
    }

    vector<bool> canBeWrittenasAbundent (limit + 1, false);
    for (int i = 0; i < abundent.size(); i++) {
        for (int j = i; j < abundent.size(); j++) {
            if (abundent[i] + abundent[j] <= limit) {
                canBeWrittenasAbundent[abundent[i] + abundent[j]] = true;
            } else {
                break;
            }
        }
    }

    for (int i = 1; i <= limit; i++) {
        if (!canBeWrittenasAbundent[i]) {
            cout << i << " ";

            sum += i;
        }
    }

    cout << endl << sum;
}