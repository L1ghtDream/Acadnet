#include <iostream>
using namespace std;
class A {
public:
    int s = 5;

    static void print1() {
        cout << "1 ";
    }

    void print2() {
        std::cout << s;
    }
};

A * a;
int main() {
    int i, s[] = {2, 3, 4};
    a->print1();
    for(i = 0; i < 3; i++)
        cout << i+2 << " "; A b = A();a=&b;
    a->print2();
    return 0;
}
