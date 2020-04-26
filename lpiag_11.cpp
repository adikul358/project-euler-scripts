#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {

    ifstream gridFile;
    int product;
    int productLargest = 0;
    int x;
    vector<vector<int>> grid(20, vector<int>(20, 0));

    gridFile.open("lpiag_11_1.txt");
    if (!gridFile) {
        cerr << "Unable to open file";
        exit(1);
    }
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            gridFile >> x;
            grid[i][j] = x;
        }
    }

    for (int i = 0; i < 20; i++) { 
        for (int j = 0; j < 17; j++){ 
            product = grid[i][j] * grid[i][j+1] * grid[i][j+2] * grid[i][j+3];
            if (product > productLargest) {
                productLargest = product;
            }
            cout << "Row " << i << ": " << grid[i][j] << " * " << grid[i][j+1] << " * " << grid[i][j+2] << " * " << grid[i][j+3] << " = " << product; 
            cout<< "\n"; 
        } 
        cout<< "\n"; 
        cout<< "\n"; 
    } 
    for (int j = 0; j < 20; j++){ 
        for (int i = 0; i < 17; i++) { 
            product = grid[i][j] * grid[i+1][j] * grid[i+2][j] * grid[i+3][j];
            if (product > productLargest) {
                productLargest = product;
            }
            cout << "Column " << j << ": " << grid[i][j] << " * " << grid[i+1][j] << " * " << grid[i+2][j] << " * " << grid[i+3][j] << " = " << product; 
            cout<< "\n"; 
        } 
        cout<< "\n"; 
        cout<< "\n"; 
    } 
    int d_counter = 0;
    for (int i = 0; i < 20; i++) { 
        int j = 0;
        int temp_i = i;
        while(temp_i < 17 && j < 17) {
            product = grid[temp_i][j] * grid[temp_i+1][j+1] * grid[temp_i+2][j+2] * grid[temp_i+3][j+3];
            if (product > productLargest) {
                productLargest = product;
            }
            cout << "South East Diagonal " << d_counter << ": " << grid[temp_i][j] << "[" << i << "][" << j << "]" << " * " << grid[temp_i+1][j+1] << "[" << i+1 << "][" << j+1 << "]" << " * " << grid[temp_i+2][j+2] << "[" << i+2 << "][" << j+2 << "]" << " * " << grid[temp_i+3][j+3] << "[" << i+3 << "][" << j+3 << "]" << " = " << product; 
            cout<< "\n"; 
            temp_i++;
            j++;
        } 
        d_counter++;
        cout<< "\n"; 
        cout<< "\n"; 
    } 
    for (int j = 0; j < 20; j++) { 
        int i = 0;
        int temp_j = j;
        while(i < 17 && temp_j < 17) {
            product = grid[i][temp_j] * grid[i+1][temp_j+1] * grid[i+2][temp_j+2] * grid[i+3][temp_j+3];
            if (product > productLargest) {
                productLargest = product;
            }
            cout << "South East Diagonal " << d_counter << ": " << grid[i][temp_j] << "[" << i << "][" << j << "]" << " * " << grid[i+1][temp_j+1] << "[" << i+1 << "][" << j+1 << "]" << " * " << grid[i+2][temp_j+2] << "[" << i+2 << "][" << j+2 << "]" << " * " << grid[i+3][temp_j+3] << "[" << i+3 << "][" << j+3 << "]" << " = " << product; 
            cout<< "\n"; 
            i++;
            temp_j++;
        } 
        d_counter++;
        cout<< "\n"; 
        cout<< "\n"; 
    } 
    d_counter = 0;
    for (int i = 0; i < 20; i++) { 
        int j = 19;
        int temp_i = i;
        while(temp_i < 17 && j > 3) {
            product = grid[temp_i][j] * grid[temp_i+1][j-1] * grid[temp_i+2][j-2] * grid[temp_i+3][j-3];
            if (product > productLargest) {
                productLargest = product;
            }
            cout << "South West Diagonal " << d_counter << ": " << grid[temp_i][j] << "[" << i << "][" << j << "]" << " * " << grid[temp_i+1][j-1] << "[" << i+1 << "][" << j-1 << "]" << " * " << grid[temp_i+2][j-2] << "[" << i+2 << "][" << j-2 << "]" << " * " << grid[temp_i+3][j-3] << "[" << i+3 << "][" << j-3 << "]" << " = " << product; 
            cout<< "\n"; 
            temp_i++;
            j--;
        } 
        d_counter++;
        cout<< "\n"; 
        cout<< "\n"; 
    } 
    for (int j = 19; j >= 0; j--) { 
        int i = 0;
        int temp_j = j;
        while(i < 17 && temp_j > 2) {
            product = grid[i][temp_j] * grid[i+1][temp_j-1] * grid[i+2][temp_j-2] * grid[i+3][temp_j-3];
            if (product > productLargest) {
                productLargest = product;
            }
            cout << "South West Diagonal " << d_counter << ": " << grid[i][temp_j] << "[" << i << "][" << j << "]" << " * " << grid[i+1][temp_j-1] << "[" << i+1 << "][" << j-1 << "]" << " * " << grid[i+2][temp_j-2] << "[" << i+2 << "][" << j-2 << "]" << " * " << grid[i+3][temp_j-3] << "[" << i+3 << "][" << j-3 << "]" << " = " << product; 
            cout<< "\n"; 
            i++;
            temp_j--;
        } 
        d_counter++;
        cout<< "\n"; 
        cout<< "\n"; 
    } 




    cout << "Largest Product = " << productLargest;

}