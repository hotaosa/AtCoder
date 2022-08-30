#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
  int k;
  cin >> k;
  if (k % 9 > 0) { cout << "0" << endl; return 0; }

  vector<mint> dp(k + 1, 0);
  dp[0] = 1;
  for (int i = 1; i <= k; ++i) {
    for (int j = max(0, i - 9); j < i; ++j) dp[i] += dp[j];
  }

  cout << dp[k].val() << endl;  
  return 0;
}