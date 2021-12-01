#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    constexpr long long MOD = 998244353LL;

    long long a, b, c;
    std::cin >> a >> b >> c;

    long long res = (a + 1) * a / 2 % MOD;
    res = res * ((b + 1) * b / 2 % MOD) % MOD;
    res = res * ((c + 1) * c / 2 % MOD) % MOD;

    std::cout << res << std::endl;
    return 0;
}
