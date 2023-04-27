#include <iostream>
#include <vector>


std::vector<int> prime_factors(int n);


int main() {
    int n;

    std::cin >> n;
    auto factors = prime_factors(n);

    std::cout << n*factors[factors.size()-1] << std::endl;
}


std::vector<int> prime_factors(int n) {
    std::vector<int> factors;

    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    return factors;
}