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

  vector<vector<int> > graph(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    graph[--a].push_back(--b);
    graph[b].push_back(a);
  }

  int k;
  cin >> k;
  vector<int> c(k);  
  for (auto &p : c) { cin >> p; --p; }

  vector<vector<int> > dist(k, vector<int>(k, INF));
  for (int i = 0; i < k; ++i) {
    vector<int> d(n, INF);
    d[c[i]] = 0;
    queue<int> que;
    que.push(c[i]);
    while (!que.empty()) {
      int v = que.front();
      que.pop();
      for (int nv : graph[v]) {
        if (d[nv] == INF) {
          d[nv] = d[v] + 1;
          que.push(nv);
        }
      }
    }
    for (int j = 0; j < k; ++j) dist[i][j] = d[c[j]];
  }
  
  vector<vector<int> > dp(1 << k, vector<int>(k, INF));
  for (int i = 0; i < k; ++i) dp[1 << i][i] = 1;
  for (int bit = 0; bit < (1 << k); ++bit) {
    for (int i = 0; i < k; ++i) {      
      if (dp[bit][i] == INF) continue;
      for (int j = 0; j < k; ++j) {
        if (j == i || dist[i][j] == INF) continue;
        chmin(dp[bit | (1 << j)][j], dp[bit][i] + dist[i][j]);
      }
    }
  }
  int res = INF;
  for (int i = 0; i < k; ++i) chmin(res, dp[(1 << k) - 1][i]);
  cout << (res < INF ? res : -1) << endl;
  return 0;
}
