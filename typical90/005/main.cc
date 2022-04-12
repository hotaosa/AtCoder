#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

int count_bit(long long n) {
  int ret = 0;
  while (n) {
    ++ret;
    n >>= 1;
  }
  return ret;
}

inline long long modpow(long long a, long long n, long long mod) {
  long long ret = 1LL;
  while(n) {
    if (n & 1LL) ret = ret * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return ret;
}

int main() {
  long long n;
  int b, k;  
  cin >> n >> b >> k;

  vector<int> c(k);
  for (auto &p : c) cin >> p;
  
  int d = count_bit(n) + 1;
  vector<vector<mint> > dp(d + 1, vector<mint>(b, 0));
  for (int ci : c) ++dp[0][ci % b];

  vector<int> pow10(d + 1);
  for (int i = 0; i <= d; ++i) pow10[i] = modpow(10, (1LL << i), b);

  for (int i = 0; i < d; ++i) {    
    for (int j = 0; j < b; ++j) {
      for (int k = 0; k < b; ++k) {
        dp[i + 1][(j * pow10[i] + k) % b] += dp[i][j] * dp[i][k];
      }
    }
  }

  vector<vector<mint> > res(d + 1, vector<mint>(b, 0));
  res[0][0] = 1;
  for (int i = 0; i < d; ++i) {
    if (n & (1LL << i)) {
      for (int j = 0; j < b; ++j) {
        for (int k = 0; k < b; ++k) {          
          res[i + 1][(j * pow10[i] + k) % b] += res[i][j] * dp[i][k];
        }
      }
    } else {
      for (int j = 0; j < b; ++j) res[i + 1][j] = res[i][j];
    }
  }
  cout << res[d][0].val() << endl;
  return 0;
}
