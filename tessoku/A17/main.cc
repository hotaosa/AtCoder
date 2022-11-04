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
  const int INF = 1 << 30;
  vector<int> a(n, INF), b(n, INF);
  for (int i = 1; i < n; ++i) cin >> a[i];
  for (int i = 2; i < n; ++i) cin >> b[i];

  vector<int> dp(n, INF);
  dp[0] = 0;

  for (int i = 1; i < n; ++i) {
    chmin(dp[i], dp[i - 1] + a[i]);
    if (i > 1) chmin(dp[i], dp[i - 2] + b[i]);
  }

  vector<int> res = {n};
  int cur = n - 1;
  while (cur > 0) {    
    if (dp[cur] == dp[cur - 1] + a[cur]) --cur;
    else cur -= 2;
    res.push_back(cur + 1);
  }
  reverse(res.begin(), res.end());
  
  cout << res.size() << endl;
  for (auto r : res) cout << r << " ";
  cout << endl;  
  return 0;
}
