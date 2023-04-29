#include <iostream>

#define maxN 0xb055

using namespace std;

int main() {
    int n, q, x, v[maxN];
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    while (q--) {
        cin >> x;
        bool found = false;
        for (int step = 0; step < n; step++) {
            if (v[step] == x) {
                cout << "fair enough\n";
                found = true;
            }
        }
        if (!found) {
            cout << "bad luck\n";
        }
    }
    return 0;
}

