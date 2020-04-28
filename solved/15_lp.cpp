#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

void printGrid(vector<vector<long long int>> grid) {
}

int main() {

    int gridSize = 20;
    vector<vector<long long int>> grid(gridSize+1, vector<long long int>(gridSize, 0));
    
    for (int i = 0; i < gridSize; i++) { 
        grid[i][gridSize] = 1; 
        grid[gridSize][i] = 1; 
    }
    
    for (int i = gridSize - 1; i >= 0; i--) {
        for (int j = gridSize - 1; j >= 0; j--) {
            grid[i][j] = grid[i+1][j] + grid[i][j+1];
            // cout << grid[i][j] << '(' << i << ', ' << j << ") ";
        }
        // cout << endl;
    }

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            cout << grid[i][j] << " ";
        }
    cout << "\n";
    }
    cout << "\n";
}