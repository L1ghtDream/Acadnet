#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

#define INPUT_FILENAME "../input.txt"
#define OUTPUT_FILENAME "../output.txt"
using namespace std;

int main() {
    vector<vector<int>> matrix;
    ifstream inputFile;
    ofstream outputFile;
    inputFile.open(INPUT_FILENAME);
    if (!inputFile.good()) {
        cout << "Failed to open" << INPUT_FILENAME << endl;
        exit(-1);
    }
    int size;
    inputFile >> size;
    for (int i = 0; i < size; i++) {
        vector<int> tmp;
        for (int j = 0; j < size; j++) {
            int x;
            inputFile >> x;
            tmp.push_back(x);
        }
        matrix.push_back(tmp);
    }

    for (int i = 0; i < size; i++) {
        sort(matrix[i].begin(), matrix[i].end());

        if((i+1) % 2 == 1){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }

    inputFile.close();

    outputFile.open(OUTPUT_FILENAME);
    if (!outputFile.good()) {
        cout << "Failed to open" << OUTPUT_FILENAME << endl;
        exit(-1);
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            outputFile << matrix[i][j] << " ";
        }
        outputFile << endl;
    }

    outputFile.close();
    return 0;
}