#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

template<typename Iterator>
void bubble_sort(Iterator begin, Iterator end) {
    bool swapped;
    do {
        swapped = false;
        for (Iterator i = begin + 1; i != end; ++i) {
            typename std::iterator_traits<Iterator>::value_type &val0 = *i;
            typename std::iterator_traits<Iterator>::value_type &val1 =
                    *(i - 1);
            if (val0 < val1) {
                std::swap(val1, val0);
                swapped = true;
            }
        }
    } while (swapped);
}

int main() {
    size_t n, i;
    int temp;
    cin >> n;
    vector<int> numbers(n);
    for (i = 0; i < n; i++) {
        cin >> temp;
        numbers[i] = temp;
    }
    bubble_sort(numbers.begin(), numbers.end());

    int sum = 0;

    for (i = n - 1; i >= n / 2; i--) {
        sum += numbers[i];
    }

    cout << sum / (n / 2) << endl;
}