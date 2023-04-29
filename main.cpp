#include <iostream>
using namespace std;

int main() {
    int n;
    int *vector;

    cin >> n;

    // Allocate memory
    vector = new int[n];

    // Read input
    for (int i = 0; i < n; i++)
        cin >> vector[i];

    // Math operations on the vector
    for (int i = 0; i < n; i++) {
        if (vector[i] % 2 == 0) {
            vector[i] *= 2;
            vector[i] += 1;
        } else
            vector[i] *= 3;
        vector[i] -= 1;
    }

    // Sum all the elements
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += vector[i];

    // Print the sum
    cout << sum << "\n";

    // Print the elements
    for (int i = 0; i < n; i++)
        cout << vector[i] << " ";
    cout << "\n";

    // Free the allocated memory
    delete[] vector;

    return 0;
}
