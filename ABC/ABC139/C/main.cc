#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  for (auto &p : h) cin >> p;

  int res = 0;
  vector<int> dp(n, 0);
  for (int i = n - 2; i >= 0; --i) {
    dp[i] = (h[i] >= h[i + 1] ? dp[i + 1] + 1 : 0);
    res = max(res, dp[i]);
  }

  cout << res << endl;  
  return 0;
}
