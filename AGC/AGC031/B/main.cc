#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> c(n);
    for (auto &p : c) std::cin >> p;
    
    std::vector<atcoder::modint1000000007> dp(n, 0);
    std::vector<int> pos(200001, 1 << 30);

    dp[0] = 1;
    pos[c[0]] = 0;

    for (int i = 1; i < n; ++i) {
        dp[i] = dp[i - 1];
        if (pos[c[i]] < i - 1) dp[i] += dp[pos[c[i]]];
        pos[c[i]] = i;
    }

    std::cout << dp[n - 1].val() << std::endl;    
    return 0;
}
