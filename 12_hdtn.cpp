#include <iostream>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;

vector<int> find_factors(int n) {
    vector<int> factors;
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            if (n/i == i) 
                factors.push_back(int(i));
            else
                factors.push_back(int(i));
                factors.push_back(int(n/i));
        } 
    } 
    return factors;
}

int main() {
    int n = 0;
    int counter = 1;
    vector<int> factors;

    while(factors.size() <= 500) {
        n += counter;
        counter++;

        factors = find_factors(n);
    }

    cout << n;
}