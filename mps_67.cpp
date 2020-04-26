#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {

    ifstream triangleFile;
    int product;
    int productLargest = 0;
    int a;
    string x;
    vector<vector<int>> inputTriangle(100, vector<int>(100, 0));
    int m = 0
    int n = 0;

    triangleFile.open("mps_67_1.txt");
    if (!triangleFile) {
        cerr << "Unable to open file";
        exit(1);
    }
    while(getline(triangleFile, x)) {
        stringstream y(x);
        while(y >> a) {
            inputTriangle[m][n] = a;
            n++;
        }
        n = 0;
        m++;
    }

    int lines = inputTriangle.size();
 
    for (int i = lines-2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            inputTriangle[i][j] += max(inputTriangle[i+1][j], inputTriangle[i+1][j+1]);
        }
    }
    cout<<inputTriangle[0][0];
}