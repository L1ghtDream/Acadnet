#include <bits/stdc++.h>
using namespace std;

double find_best_phone(std::vector<int> &phones) {
    sort(phones.begin(), phones.end());
    int number_phones = phones.size();
    if (number_phones % 2 == 1) {
        return phones[number_phones / 2];
    } else {
        return (phones[number_phones / 2 - 1] + phones[number_phones / 2]) / 2.0;
    }
}


int main() {
    int n;
    ifstream fin("../input.txt");
    fin >> n;
    vector<int> phones(n,0);
    for (int i = 0; i < n; ++i) {
        fin >> phones[i];
    }

    ofstream fout("../output.txt");
    fout << find_best_phone(phones) << "\n";
    fin.close();
    fout.close();
    return 0;
}