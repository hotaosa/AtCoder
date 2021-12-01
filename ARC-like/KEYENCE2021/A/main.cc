#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> a(n);
    std::cin >> a[0];
    for (int i = 1; i < n; ++i) {
        std::cin >> a[i];
        a[i] = std::max(a[i], a[i - 1]);
    }

    long long res = 0LL;
    for (int i = 0; i < n; ++i) {
        long long b;
        std::cin >> b;
        res = std::max(res, b * a[i]);
        std::cout << res << std::endl;
    }

    return 0;
}
