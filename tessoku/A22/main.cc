#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) { a = b; return true; }
  return false;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n - 1), b(n - 1);
  for (auto &p : a) { cin >> p; --p; }
  for (auto &p : b) { cin >> p; --p; }

  const int INF = 1 << 30;
  vector<int> dp(n, -INF);
  dp[0] = 0;
  for (int i = 0; i < n - 1; ++i) {
    chmax(dp[a[i]], dp[i] + 100);
    chmax(dp[b[i]], dp[i] + 150);
  }
  
  cout << dp.back() << endl;  
  return 0;
}
