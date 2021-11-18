#include <iostream>
#include <vector>
#include <atcoder/modint>

using mint = atcoder::modint1000000007;

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &p : a) std::cin >> p;

    std::vector<std::vector<mint> > dp(n, std::vector<mint>(2, 0));
    std::vector<std::vector<mint> > cnt(n, std::vector<mint>(2, 0));
    
    dp[0][0] = a[0];
    cnt[0][0] = 1;

    for (int i = 0; i < n - 1; ++i) {
        dp[i + 1][0] = dp[i][0] + a[i + 1] * cnt[i][0] + dp[i][1] + a[i + 1] * cnt[i][1];
        dp[i + 1][1] = dp[i][0] - a[i + 1] * cnt[i][0];
        cnt[i + 1][0] = cnt[i][0] + cnt[i][1];
        cnt[i + 1][1] = cnt[i][0];
    }

    std::cout << (dp[n - 1][0] + dp[n - 1][1]).val() << std::endl;    
    return 0;
}
