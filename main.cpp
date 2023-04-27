#include <iostream>
#include <vector>

#define POLI_FORBIDDEN_DREAM 6969696969

using zacusca_t = std::vector<std::vector<int>>;
using strangers_t = std::vector<long long>;


int main() {
    int n;
    std::cin >> n;

    zacusca_t zacusca(n + 1, std::vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            std::cin >> zacusca[i][j];
        }
    }

    strangers_t strangers(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        std::cin >> strangers[i];
    }

    std::vector<long long int> dp(n + 1);
    // Caz de baza
    dp[0] = 0;

    // Caz general
    for (int i = 1; i <= n; ++i) {
        // Adaugam interactiunile cu strainii.
        dp[i] = strangers[i];

        // Adaugam interactiunile de tip zacusca.
        for (int j = 1; j < i; ++j) {
            if (zacusca[j][i]) {
                dp[i] = (dp[i] + dp[j]) % POLI_FORBIDDEN_DREAM;
            }
        }
    }

    // Solutie: X = sum(dp[i])
    long long int X = 0;
    for (int i = 1; i <= n; ++i) {
        X = (X + dp[i]) % POLI_FORBIDDEN_DREAM;
    }

    std::cout << X << std::endl;

    return 0;
}

