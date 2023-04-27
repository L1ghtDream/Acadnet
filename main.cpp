#include <iostream>

#define N 2586134

unsigned int _ = 0;

int reference(int a);

void add(int __) {
    _ += __;
}

void add_again(int __) {
    _ += __ + 2;
}

void add_once_again(int __) {
    _ += __ * 3 + 2;
}

void compute_number(int mySweetVar) {
    if (mySweetVar % 2 == 0) {
        for (int i = N; i >= 0; i--) {
            add(i);
        }
    } else if (mySweetVar % 3 == 0) {
        for (int i = N; i >= 0; i--) {
            add_again(i);
        }
    } else {
        for (int i = N; i >= 0; i--) {
            add_once_again(i);
        }
    }

}

int main(void) {
    int mySweetVar;
    std::cin >> mySweetVar;
    _ = mySweetVar;
    compute_number(mySweetVar);
    std::cout << _ << "\n";
}

