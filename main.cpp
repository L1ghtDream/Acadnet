/*
    Acadnet 2017 - Etapa Interjudeteana
    Problema A - Optimize Nule
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>

using namespace std;

#define INPUT_FILENAME "../input.txt"
#define OUTPUT_FILENAME "../output.txt"

/*
	Aceasta este singura functie pe care aveti
	voie sa o modificati / rescrieti.
*/
void nule(std::vector<int> &v) {
    vector<int> toRemove;
    int count = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 0) {
            v.erase(v.begin() + i);
            i--;
            count++;
        }
    }

    for(int i=0;i<count;i++){
        v.push_back(0);
    }
}

int main(void) {
    std::vector<int> v;
    int size, i, x;
    std::ifstream input_file;
    std::ofstream output_file;

    // Read vector from input file
    input_file.open(INPUT_FILENAME);
    if (!input_file.good()) {
        std::cout << "Failed to open " << INPUT_FILENAME << std::endl;
        exit(-1);
    }

    input_file >> size;

    v.reserve(size);

    for (i = 0; i < size; i++) {
        input_file >> x;
        v.push_back(x);
    }

    input_file.close();


    // Call nule() function
    nule(v);

    // Print vector to output file
    output_file.open(OUTPUT_FILENAME);
    if (!output_file.good()) {
        std::cout << "Failed to open " << OUTPUT_FILENAME << std::endl;
        exit(-1);
    }

    output_file << size << std::endl;
    for (i = 0; i < size; i++)
        output_file << v[i] << " ";

    output_file << std::endl;
    output_file.close();
    return 0;
}
