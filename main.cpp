#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    string target_language;
    map<string, string> language_mapping;
    string phrase;

    cin >> n >> target_language;
    for (int i = 1; i <= n; i++) {
        string keyword, language, replaced_with;
        cin >> keyword >> language >> replaced_with;
        if (language != target_language)
            continue;

        language_mapping[keyword] = replaced_with;
    }

    getline(cin, phrase);
    getline(cin, phrase);

    string word;
    stringstream phrase_stream(phrase);
    vector<string> words;
    while (getline(phrase_stream, word, ' '))
        words.push_back(word);

    for (int i = 0; i < int(words.size()); i++)
        if (language_mapping.count(words[i]))
            words[i] = language_mapping[words[i]];

    for (int i = 0; i < int(words.size()); i++) {
        cout << words[i];
        if (i + 1 != int(words.size()))
            cout << " ";
        else
            cout << "\n";
    }

    return 0;
}
