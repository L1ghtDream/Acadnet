#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

bool is_prime(unsigned long long x) {
    if (x == 2) return true;
    for (long long i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

int main() {
    unsigned long long n, count = 0, sum = 0;
    char citire[100];
    gets(citire);
    n = atoi(citire);
    for (int i = 2; i < n; i++) {
        if (is_prime(i)){
            count++;
            sum += i;
        }
    }
    std::cout << sum << " " << count << std::endl;
}