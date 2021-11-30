#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        ++cnt[a];
    }

    int res = 0;
    for (int i = 0; i <= n; ++i) {
        res += i * (k - std::min(k, cnt[i]));
        k = std::min(k, cnt[i]);
    }

    std::cout << res << std::endl;
    return 0;
}
