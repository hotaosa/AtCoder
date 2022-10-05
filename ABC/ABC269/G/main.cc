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

  int sum = 0;
  map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    sum += a;
    ++mp[b - a];
  }

  vector<pair<int, int> > vp;
  for (auto m : mp) {
    int cnt = m.second;
    int c = 1;
    while (c <= cnt) {
      vp.emplace_back(m.first * c, c);
      cnt -= c;
      c <<= 1;
    }
    if (cnt > 0) vp.emplace_back(m.first * cnt, cnt);
  }
  int siz = vp.size();

  vector<vector<int> > dp(siz + 1, vector<int>(m + 1, INF));
  dp[0][sum] = 0;

  for (int i = 0; i < siz; ++i) {
    for (int j = 0; j <= m; ++j) {
      chmin(dp[i + 1][j], dp[i][j]);
      if (j + vp[i].first >= 0 && j + vp[i].first <= m) {
        chmin(dp[i + 1][j + vp[i].first], dp[i][j] + vp[i].second);
      }
    }
  }

  for (int i = 0; i <= m; ++i) {
    cout << (dp[siz][i] < INF ? dp[siz][i] : -1) << endl;
  }  
  return 0;
}
