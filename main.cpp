#include <bits/stdc++.h>                                // You cannot change this line!
// You cannot change this line!
int main() {                                            // You cannot change this line!
    int n;                                              // You cannot change this line!
    std::cin >> n;                                      // You cannot change this line!
    // You cannot change this line!
    std::vector<unsigned int> gpns;                     // You cannot change this line!
    for (int i = 1; i <= n; ++i) {                      // You cannot change this line!
        unsigned int gpn;                               // You cannot change this line!
        std::cin >> gpn;                                // You cannot change this line!
        gpns.push_back(gpn);                            // You cannot change this line!
    }                                                   // You cannot change this line!
    // You cannot change this line!
    // You cannot change this line!
    auto max_gpn = -1;                                  // You cannot change this line!
    for (auto gpn : gpns) {                             // You cannot change this line!
        if ((int)gpn > (int)max_gpn) {                            // You can edit this line for a beer!
            max_gpn = gpn;                              // You can edit this line for a beer!
        }                                               // You can edit this line for a beer!
    }                                                   // You cannot change this line!
    std::cout << max_gpn << "\n";                       // You cannot change this line!
    return 0;                                           // You cannot change this line!
}                                                       // You cannot change this line!