#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &p : a) std::cin >> p;

    std::vector<int> res(n, 0);
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {
            res[i] = 1 - res[i];
            res[i + 1] = 1 - res[i + 1];
        }
    }

    for (auto &p : res) std::cout << p << " ";
    std::cout << std::endl;
    return 0;
}
