#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> s(n, 0);
    for (auto &ss : s) {
        for (int i = 0; i < 3; ++i) {
            int p;
            std::cin >> p;
            ss += p;
        }
    }

    std::vector<int> s_copy = s;
    std::sort(s_copy.begin(), s_copy.end(), std::greater<>());

    for (auto &ss : s) std::cout << (ss + 300 >= s_copy[k - 1] ? "Yes" : "No" ) << std::endl;
    return 0;
}
