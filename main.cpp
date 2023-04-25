#include <iostream>
#include <string>
#include <string>
#include <cctype>
#include <vector>
#include <set>
#include <fstream>
#include <string.h>


using namespace std;

// this is the function that you have to fill it
// submit ONLY this function
unsigned long string_hash(unsigned char *string) {
    long hash = 5381;
    int c;

    while (c = *string++)
        hash = ((hash << 5) + hash) + c;

    return hash;
}


vector<string> get_words(string file_name) {
    vector<string> result;

    ifstream file(file_name);
    string word;
    while (file >> word) result.push_back(word);

    return result;
}

int main() {
    vector<std::string> words = get_words("../words.txt");
    set<int> hashes;

    int duplicates = 0;

    for (auto word: words) {
        int hash = string_hash((unsigned char *) strdup(word.c_str()));

        if (hashes.count(hash) > 0) {
            duplicates++;
        } else {
            hashes.insert(hash);
        }
    }

    cout << "Your hashing function has " << duplicates << " collisions." << endl;
    return 0;
}
