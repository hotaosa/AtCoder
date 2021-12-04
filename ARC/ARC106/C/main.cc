#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    int n, m;
    std::cin >> n >> m;
    if (n == 1) { std::cout << (m == 0 ? "1 2" : "-1") << std::endl; return 0; }
    if (m < 0 || m >= n - 1) { std::cout << "-1" << std::endl; return 0; }

    std::vector<std::pair<int, int> > res(n);
    res[0].first = 1;
    res[0].second = (m + 2) * 2;
    for (int i = 1; i < m + 2; ++i) {
        res[i].first = i * 2;
        res[i].second = i * 2 + 1;
    }
    for (int i = m + 2; i < n; ++i) {
        res[i].first = i * 2 + 1;
        res[i].second = i * 2 + 2;
    }

    for (auto &p : res) std::cout << p.first << " " << p.second << std::endl;
    return 0;    
}
