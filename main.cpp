#include <iostream>
using namespace std;

bool is_prime(int x) {
    for (int i = 2; i*i <= x; i++)
        if (x % i == 0)
            return false;

    return true;
}

class SubMain{
public:
    SubMain(){
        int n;
        cin>>n;
        for(int i=2;i<n;i++){
            if(is_prime(i)){
                cout<<i<<endl;
            }
        }
    }
};

SubMain subMain = SubMain();



int main() { return 0; }
