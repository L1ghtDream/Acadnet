#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    // următoarea linie oferă posibilitatea de a citi din fisierul "input.txt"
    // folosind în continuare cin!
    freopen("../input.txt", "r", stdin); // este corectă această linie, nu trebuie să modifici aici!

    // Observati liniile 10-15. Nu trebuie să le modificati.
    int gigel;
    gigel = 1, 2, 3; // gigel == ?
    ++gigel = 2;// gigel == ?
    ++gigel = 3;// gigel == ?

    // Acum să terminăm cu prostiile s să îl citim pe gigel din
    // fisier. Gigel este (un) întreg.

    cin >> gigel;

    // Aveti voie să modificati linia 21.
    int enumeration = 1;
    ++enumeration;

    // Aveti voie să modificati linia 25.
    int a = gigel, b = 0, c = 3, d = 4, e = 5, f = gigel-1;
    int foo, bar;
    foo = ++f, e - b, c - a;
    bar = (a + b, ++b + ++c - --a + a++, f);
    cout << (foo + bar) << "\n";
    return 0;
}
