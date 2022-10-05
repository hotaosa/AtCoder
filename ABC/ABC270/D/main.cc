#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) { a = b; return true; }
  return false;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(k);
  for (auto &p : a) cin >> p;

  vector<int> dp(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < k; ++j) {
      if (i - a[j] >= 0) {
        chmax(dp[i], i - dp[i - a[j]]);
      }
    }
  }

  cout << dp[n] << endl;  
  return 0;
}
