#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    // următoarea linie oferă posibilitatea de a citi din fisierul "input.txt"
    // folosind în continuare cin!
    freopen("../input.txt", "r", stdin); // este corectă această linie, nu trebuiasă modifici aici!

    int values;
    cin >> values;

    double x = 1.0l, limit;

    // trebuie sa modifici aceasta bucla
    while (values-- > 0) {
        x = x / 2;
        double half = x / 2;
        double halfSine = sin(half);
        limit = halfSine / half;
        limit = limit * limit / 2;
    }
    // nu modifica dupa aceasta linie

    cout << x << " " << limit << "\n";

    return 0;
}