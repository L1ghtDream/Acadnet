#include <bits/stdc++.h>

// You can't use any of the following words: for, while, return, begin, end, goto.		// You can NOT edit this
auto sum(const std::vector<int> &v, const int left, const int right) {					// You can edit this
    if (left == right) {																// You can edit this
        return v[left]; 																// You can edit this
    } else {																			// You can edit this
        auto mid = (left+right)	/2		;								// You can edit this
        int res = sum(v, left, mid) + sum(v, mid + 1, right);				// You can edit ths
        return res;																		// You can NOT edit this
    }
}

int main() {
    int n;                                                  							// You can NOT edit this
    std::vector<int> v;																	// You can NOT edit this
    std::cin >> n;																		// You can NOT edit this
    v.resize(n); 																		// You can NOT edit this
    // You can NOT edit this
    for (int i = 0; i < n; i++) {														// You can NOT edit this
        std::cin >> v[i];																// You can NOT edit this
    }																					// You can NOT edit this
    std::cout << sum(v, 0, v.size() - 1) << "\n";										// You can NOT edit this
    return 0;																			// You can NOT edit this
}
