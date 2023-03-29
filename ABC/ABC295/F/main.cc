#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

long long Solve(string s, long long num) {
  vector<int> x, y;
  for (auto c : s) x.push_back(c - '0');
  while (num) {
    y.push_back(num % 10);
    num /= 10;
  }
  reverse(y.begin(), y.end());
  int n = x.size(), m = y.size();

  long long ret = 0;
  for (int d = 0; d + n <= m; ++d) {
    vector dp(m + 1, vector(2, vector<long long>(2, 0)));
    dp[0][0][1] = 1;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k) {
          for (int nx = 0; nx < 10; ++nx) {
            if (i >= d && i < d + n) {
              if (nx != x[i - d]) continue;
              if (k && nx == 0) continue;
            } 
            if (!j && nx > y[i]) continue;
            int nj = (!j && nx == y[i]) ? 0 : 1;
            int nk = (k && nx == 0) ? 1 : 0;
            dp[i + 1][nj][nk] += dp[i][j][k];
          }
        }
      }
    }
    ret += dp[m][1][0] + dp[m][0][0];
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);

  int t;
  cin >> t;
  while (t--) {
    string s;
    long long l, r;
    cin >> s >> l >> r;
    cout << Solve(s, r) - Solve(s, l - 1) << endl;
  }
  
  return 0;
}
