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
    int u, v;
    cin >> u >> v;
    graph[--u].push_back(--v);
    //graph[v].push_back(u);
  }

  int s, t;
  cin >> s >> t;
  --s; --t;

  vector<vector<int> > dp(n, vector<int>(3, INF));
  dp[s][0] = 0;
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<> > pque;
  pque.emplace(0, s, 0);
  while (!pque.empty()) {
    int d = get<0>(pque.top());
    int v = get<1>(pque.top());
    int cur = get<2>(pque.top());
    pque.pop();
    if (d > dp[v][cur]) continue;
    for (int nv : graph[v]) {
      if (cur < 2 && chmin(dp[nv][cur + 1], d)) pque.emplace(d, nv, cur + 1);
      if (cur == 2 && chmin(dp[nv][0], d + 1)) pque.emplace(d + 1, nv, 0);
    }
  }

  cout << (dp[t][0] < INF ? dp[t][0] : -1) << endl;
  return 0;
}
