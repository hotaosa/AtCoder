#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (auto &p : a) std::cin >> p;

    if (a[0] != 0) { std::cout << "-1" << std::endl; return 0; }
    for (int i = 1; i < n; ++i) if (a[i] - a[i - 1] > 1) { std::cout << "-1" << std::endl; return 0; }

    a.push_back(1 << 30);
    long long res = 0LL;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == a[i + 1] - 1) continue;
        res += a[i];        
    }

    std::cout << res << std::endl;
    return 0;
}
