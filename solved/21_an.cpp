#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

int sumOfFactors(int n) {
    int s = 0;
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            s += i;
            if (n/i != i) {
                s += n/i;
            }
        } 
    } 
    return s - n;
}


int main() {
    int s = 0;
    for (int i = 1; i <= 10000; i++) {
        int sumI = sumOfFactors(i);
        if (sumI != i) {
            int sumSumI = sumOfFactors(sumI);
            if (i == sumSumI) {
                printf("d(%d) = %d, d(%d) = %d\n", i, sumI, sumI, sumSumI);
                s += i;
            }
        }
    }
    cout << endl << endl << s;
}