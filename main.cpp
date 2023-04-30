#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;

    cin >> n;

    for(int current=sqrt(n);current>=0;current--){
        if(current*current <= n){
            cout<<current<<" ";
        }
    }

    return 0;
}
