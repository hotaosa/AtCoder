#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    std::string s;
    int k;
    std::cin >> s >> k;
    int n = s.length();

    std::vector<int> num;
    for (char c : s) num.push_back(c - '0');

    std::vector<std::vector<std::vector<int> > > dp(n + 1, std::vector<std::vector<int> > (k + 1, std::vector<int>(2, 0)));
    ++dp[0][0][0];

    for (int i = 0; i < n; ++i) {
        int nx = num[i];
        for (int j = 0; j <= k; ++j) {
            if (nx > 0) dp[i + 1][j][1] += dp[i][j][1] + dp[i][j][0];
            else {
                dp[i + 1][j][1] += dp[i][j][1];
                dp[i + 1][j][0] += dp[i][j][0];
            }
        }
        for (int j = 1; j <= 9; ++j) {
            for (int l = 0; l < k; ++l) {
                dp[i + 1][l + 1][1] += dp[i][l][1];
                if (j < nx) dp[i + 1][l + 1][1] += dp[i][l][0];
                else if (j == nx) dp[i + 1][l + 1][0] += dp[i][l][0];
            }
        }
    }

    std::cout << dp[n][k][0] + dp[n][k][1] << std::endl;    
    return 0;
}
