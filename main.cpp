#include<bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long a, b;
    cin >> a >> b;
    if (b > INT_MAX / a) { // Poti modifica doar aceasta linie!
        cout << "Nu";
    } else {
        cout << "Da";
    }
    return 0;
}