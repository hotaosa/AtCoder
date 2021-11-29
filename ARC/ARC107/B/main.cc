#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    long long n, k;
    std::cin >> n >> k;

    auto devide = [n](long long m) -> long long {
        return n - std::abs(n + 1 - m);
    };

    long long res = 0LL;
    for (long long x = 2; x <= 2 * n; ++x) {
        long long y = x + k;
        if (y < 2LL || y > 2LL * n) continue;
        res += devide(x) * devide(y);
    }

    std::cout << res << std::endl;
    return 0;
}
