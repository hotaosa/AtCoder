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

  vector<int> res = {n};
  int cur = n - 1;
  while (cur > 0) {
    if (dp[cur - 1] + abs(h[cur - 1] - h[cur]) == dp[cur]) {
      --cur;
    } else {
      cur -= 2;
    }
    res.push_back(cur + 1);
  }

  reverse(res.begin(), res.end());
  cout << res.size() << endl;
  for (auto r : res) cout << r << endl;
  return 0;
}
