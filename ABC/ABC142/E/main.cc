#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr int INF = 1 << 30;

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> price(m);
  vector<int> key(m, 0);
  for (int i = 0; i < m; ++i) {
    int b;
    cin >> price[i] >> b;    
    for (int j = 0; j < b; ++j) {
      int c;
      cin >> c;
      key[i] |= (1 << --c);
    }
  }

  vector<vector<int> > dp(m + 1, vector<int>(1 << n, INF));
  dp[0][0] = 0;

  for (int i = 0; i < m; ++i) {
    for (int bit = 0; bit < (1 << n); ++bit) {
      chmin(dp[i + 1][bit], dp[i][bit]);
      chmin(dp[i + 1][bit | key[i]], dp[i][bit] + price[i]);
    }
  }

  int res = dp[m].back();
  if (res == INF) res = -1;
  cout << res << endl;
  return 0;
}
