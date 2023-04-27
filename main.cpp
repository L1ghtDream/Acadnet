#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Statistics {
    std::vector<int> numbers;

public:
    Statistics() {
        numbers.clear();
        int tmp;

        int n;
        cin>>n;
        //while (std::cin >> tmp) {
        for(int i=0;i<n;i++){
            cin>>tmp;
            numbers.push_back(tmp);
        }
    }

    int sum() {
        int s = 0;

        for (auto n: numbers)
            s += n;

        return s;
    }

    float median() {
        const auto middle_itr = numbers.begin() + numbers.size() / 2;
        std::nth_element(numbers.begin(), middle_itr, numbers.end());

        if (numbers.size() % 2 == 0) {
            const auto left_mid_itr = std::max_element(numbers.begin(), middle_itr);
            return (*left_mid_itr + *middle_itr) / 2;
        } else {
            return *middle_itr;
        }
    }

    float mean() {
        return (float)sum() / numbers.size();
    }
};


int main() {
    Statistics stats;

    std::cout << stats.sum()
              << " " << stats.median()
              << " " << stats.mean() << std::endl;

    return 0;
}