#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  long long a, b;
  cin >> a >> b;

  vector<int> prime;
  for (int i = 2; i <= b - a; ++i) {
    bool is_prime = true;    
    for (int j = 2; j * j <= i; ++j) is_prime &= (i % j != 0);
    if (is_prime) prime.push_back(i);
  }

  int m = prime.size();
  int n = b - a + 1;
  vector<vector<long long> > dp(n + 1, vector<long long>(1 << m, 0));
  dp[0][0] = 1;

  vector<int> add_bit(n, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if ((a + i) % prime[j] == 0) add_bit[i] |= (1 << j);
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < (1 << m); ++j) {
      dp[i + 1][j] += dp[i][j];
      if (!(j & add_bit[i])) dp[i + 1][j | add_bit[i]] += dp[i][j];
    }
  }

  long long res = 0;
  for (auto r : dp[n]) res += r;
  cout << res << endl;  
  return 0;
}
