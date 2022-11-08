#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  for (auto &p : h) cin >> p;

  const int INF = 1 << 30;
  vector<int> dp(n, INF);
  dp[0] = 0;

  for (int i = 0; i < n - 1; ++i) {
    chmin(dp[i + 1], dp[i] + abs(h[i] - h[i + 1]));
    if (i < n - 2) chmin(dp[i + 2], dp[i] + abs(h[i] - h[i + 2]));
  }

  cout << dp.back() << endl;  
  return 0;
}
