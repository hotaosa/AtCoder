#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int> > res;
    if (n & 1) {
        for (int i = 1; i < n; ++i) res.push_back(std::make_pair(std::min(i, n), std::max(i, n)));
        int sum = (n + 1) * n / 2;
        int sum1 = n * (n - 1) / 2;
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                if (j == i || j == sum - i - sum1) continue;
                res.push_back(std::make_pair(std::min(i, j), std::max(i, j)));
            }
        }
    } else {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (j == i || j == n + 1 - i) continue;
                res.push_back(std::make_pair(std::min(i, j), std::max(i, j)));
            }
        }
    }

    std::sort(res.begin(), res.end());
    res.erase(std::unique(res.begin(), res.end()), res.end());
    std::cout << res.size() << std::endl;
    for (auto &p : res) std::cout << p.first << " " << p.second << std::endl;
    return 0;
}
