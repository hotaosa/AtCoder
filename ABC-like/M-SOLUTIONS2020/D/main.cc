#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (auto &p : a) std::cin >> p;

    long long res = 1000LL;
    for (int i = 1; i < n; ++i) {
        if (a[i] > a[i - 1]) {
            long long stock = res / a[i - 1];
            res = (res % a[i - 1]) + stock * a[i];
        }
    }

    std::cout << res << std::endl;
    return 0;
}
