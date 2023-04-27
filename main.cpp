#include <iostream>
#include <iomanip>


const double PI = 3.14159265;

int main() {
    int n, a, b;

    // this is fine
    std::cout << std::fixed;

    std::cin >> n;
    for (int i = 0; i < n; i++){
        std::cin >> a >> b;
        std::cout << PI * a * b << std::endl;
    }


    return 0;
}