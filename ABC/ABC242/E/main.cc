#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

int solve(int n, string s) {
  string pre = s.substr(0, n / 2);
  string suf = s.substr((n + 1) / 2, n / 2);
  reverse(pre.begin(), pre.end());

  vector<mint> dp((n + 1) / 2, 0);
  dp[0] = s[0] - 'A';
  for (int i = 1; i < (n + 1) / 2; ++i) dp[i] = dp[i - 1] * 26 + (s[i] - 'A');
  mint res = dp.back();
  if (pre <= suf) ++res;
  return res.val();
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    cout << solve(n, s) << endl;
  }
  return 0;
}
