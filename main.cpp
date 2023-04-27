#include <iostream>
#include <stdlib.h>
using namespace std;

int main(void) {
    int a,b = 0;
    srand(66);
    a = rand();                     // This is
    b = rand();                     // "pure luck"
    if ((a == b) && (a-1 == b-1))
    {
        std::cout << "fail\n";
        return 0;
    }
    std::cout << "success\n";
    return 0;
}
