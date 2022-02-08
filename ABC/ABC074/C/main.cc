#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) { a = b; return true; }
  return false;
}

int main() {
  int a, b, c, d, e, f;  
  cin >> a >> b >> c >> d >> e >> f;
  vector<int> dp(f + 1, -1);

  auto can_dissolve = [&](int sum, int solute) -> bool {
    return solute * (100 + e) <= e * sum;
  };

  auto update = [&]() -> bool {
    bool ret = false;
    vector<int> nx = dp;
    for (int i = 0; i <= f; ++i) {
      if (dp[i] < 0) continue;
      if (i + 100 * a <= f && chmax(nx[i + 100 * a], dp[i])) ret = true;
      if (i + 100 * b <= f && chmax(nx[i + 100 * b], dp[i])) ret = true;
      if (i + c <= f && can_dissolve(i + c, dp[i] + c) && chmax(nx[i + c], dp[i] + c)) ret = true;
      if (i + d <= f && can_dissolve(i + d, dp[i] + d) && chmax(nx[i + d], dp[i] + d)) ret = true;
    }
    dp = nx;
    return ret;
  };

  dp[0] = 0;
  while (update()) { };

  pair<int, int> res = make_pair(f, 0);
  for (int i = 0; i <= f; ++i) {
    if (res.first * dp[i] > i * res.second) res = make_pair(i, dp[i]);
  }
  if (res.second == 0) cout << 100 * a << " " << "0" << endl;
  else cout << res.first << " " << res.second << endl;
  return 0;
}
