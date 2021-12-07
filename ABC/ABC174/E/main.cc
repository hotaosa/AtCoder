#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    int n;
    long long k;
    std::cin >> n >> k;
    std::vector<long long> a(n);
    long long ma = 0LL;
    for (auto &p : a) { std::cin >> p; ma = std::max(ma, p); }

    auto judge = [&](long long m) -> bool {
        if (m == 0) return false;
        long long sum = 0;
        for (auto p : a) sum += (p + m - 1) / m - 1;
        return sum <= k;
    };

    long long l = 0, r = ma;
    while (r - l > 1LL) {
        long long m = (r + l) / 2LL;
        if (judge(m)) r = m;
        else l = m;
    }
    std::cout << r << std::endl;
    return 0;
}
