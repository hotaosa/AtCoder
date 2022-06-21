#include <iostream>
#include <vector>
#include <atcoder/modint>

using namespace std;
using mint = atcoder::modint998244353;

int main() {
  long long n, m;
  cin >> n >> m;

  int d = 0;
  long long mm = m;
  while (mm) { ++d; mm >>= 1; }  
  if (n > d) { cout << "0" << endl; return 0; }
      
  vector<vector<mint> > dp(n + 1, vector<mint>(d + 1, 0));  
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= d; ++j) {
      for (int k = 0; k < j; ++k) dp[i][j] += dp[i - 1][k];
      if (j < d) dp[i][j] *= mint(1LL << (j - 1));
      else dp[i][j] *= mint(m - (1LL << (j - 1)) + 1);      
    }
  }
  
  mint res = 0;
  for (auto r : dp.back()) res += r;
  cout << res.val() << endl;
  return 0;
}