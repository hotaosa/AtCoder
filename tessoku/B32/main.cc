#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(k);
  for (auto &p : a) cin >> p;  

  vector<bool> dp(n + 1, false);
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < k; ++j) {
      if (dp[i]) continue;
      if (a[j] <= i && !dp[i - a[j]]) dp[i] = true;
    }
  }

  cout << (dp[n] ? "First" : "Second") << endl;
  return 0;
}
