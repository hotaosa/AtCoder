#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  long long n, k;
  cin >> n >> k;

  vector<int> v;
  while (n) {
    v.push_back(n % 10);
    n /= 10;
  }
  reverse(v.begin(), v.end());

  int len = v.size();
  vector<vector<map<long long, long long> > > dp(len, vector<map<long long, long long> >(2));

  for (int i = 1; i < v[0]; ++i) dp[0][1][i] = 1;
  dp[0][0][v[0]] = 1;

  for (int i = 1; i < len; ++i) {
    for (int j = 0; j < 10; ++j) {
      if (j > 0) ++dp[i][1][j];
      for (auto m : dp[i - 1][1]) {
        dp[i][1][m.first * j] += m.second;
      }
      for (auto m : dp[i - 1][0]) {
        if (j < v[i]) dp[i][1][m.first * j] += m.second;
        if (j == v[i]) dp[i][0][m.first * j] += m.second;
      }
    }
  }

  long long res = 0;
  for (auto m : dp[len - 1][0]) if (m.first <= k) res += m.second;
  for (auto m : dp[len - 1][1]) if (m.first <= k) res += m.second;
  cout << res << endl;
  return 0;
}
