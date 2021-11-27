#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    constexpr int n = 1 << 20;
    std::vector<long long> a(n, -1);

    std::set<int> se;
    for (int i = 0; i < n; ++i) se.insert(i);

    int q;
    std::cin >> q;
    while (q--) {
        int t;
        long long x;
        std::cin >> t >> x;

        if (t == 1) {
            auto p = se.lower_bound(x % n);
            if (p == se.end()) p = se.begin();
            a[*p] = x;
            se.erase(*p);
        } else {
            std::cout << a[x % n] << std::endl;
        }
    }
    return 0;
}
