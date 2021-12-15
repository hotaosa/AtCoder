#include <bits/stdc++.h>
#include <atcoder/all>

using mint = atcoder::modint998244353;

int main() {
    long long n;
    std::cin >> n;

    mint res = 0;
    for (long long i = 1; i * i <= n; ++i) {
        res += (n - i * i) / (2 * i) + 1;
    }

    std::cout << res.val() << std::endl;
    return 0;
}
