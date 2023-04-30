#include <iostream>
#include <cstdio>

using namespace std;

int fibbo(int n);

int main() {
    // următoarea linie oferă posibilitatea de a citi din fisierul "input.txt"
    // folosind în continuare cin!
    freopen("../input.txt", "r", stdin); // este corectă această linie, nu trebuie să modifici aici!
    int n;
    cin >> n;
    cout << fibbo(n) << "\n";
    return 0;
}

int fibbo(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    int a = 1; //fibbo[1]
    int b = 2; //fibbo[2]

    for (int i = 3; i <= n; ++i) {
        int lastA = a;
        int lastB = b;
        a = b;
        b = lastA+lastB;
    }
    return b;
}