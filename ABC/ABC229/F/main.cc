#include <bits/stdc++.h>
#include <atcoder/all>

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

int main() {
    constexpr long long INF = 1LL << 60;
    int n;
    std::cin >> n;

    std::vector<long long> va(n + 1, 0LL), vb(n + 1, 0LL);
    for (int i = 1; i <= n; ++i) std::cin >> va[i];
    for (int i = 1; i <= n; ++i) std::cin >> vb[i];

    std::vector<std::vector<std::vector<long long> > > dp(n + 1, std::vector<std::vector<long long> > (2, std::vector<long long>(2, INF)));
    dp[1][0][0] = va[1];
    dp[1][1][1] = 0LL;

    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                for (int l = 0; l < 2; ++l) {
                    chmin(dp[i][j][k], dp[i - 1][l][k] + (j == 0 ? va[i] : 0) + (j == l ? vb[i - 1] : 0LL));
                }
            }
        }
    }

    long long res = INF;
    for (int j = 0; j < 2; ++j) for (int k = 0; k < 2; ++k) chmin(res, dp[n][j][k] + (j == k ? vb[n] : 0LL));
    std::cout << res << std::endl;
    return 0;
}
