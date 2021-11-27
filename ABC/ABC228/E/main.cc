#include <bits/stdc++.h>
#include <atcoder/all>

using mint = atcoder::modint;

int main() {
    constexpr long long MOD = 998244353LL;
    long long n, k, m;
    std::cin >> n >> k >> m;
    if (m % MOD == 0LL) { std::cout << "0" << std::endl; return 0; }

    mint::set_mod(MOD - 1);
    long long v = mint(k).pow(n).val();
    mint::set_mod(MOD);
    std::cout << mint(m).pow(v).val() << std::endl;
    return 0;
}
