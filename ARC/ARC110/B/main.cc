#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    int n;
    std::string s = "110", t;
    std::cin >> n >> t;

    long long res = 0LL;

    for (int i = 0; i < 3; ++i) {
        bool ok = true;
        for (int j = 0; j < n; ++j) ok &= (s[(i + j) % 3] == t[j]);
        if (ok) res += 10000000001 - (n + i + 2) / 3;
    }

    std::cout << res << std::endl;
    return 0;
}
