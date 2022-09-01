#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

constexpr int INF = 1 << 30;

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

int cost(const vector<vector<int> > &graph, int s, int t, int c) {
  auto g = graph;
  int n = graph.size();
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (graph[i][j] == -1) g[i][j] = c;

  vector<int> dist(n, INF);
  dist[s] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pque;
  pque.emplace(dist[s], s);
  while (!pque.empty()) {
    int d = pque.top().first;
    int v = pque.top().second;
    pque.pop();
    if (d > dist[v]) continue;
    for (int nv = 0; nv < n; ++nv) {
      if (chmin(dist[nv], d + g[v][nv])) pque.emplace(dist[nv], nv);
    }
  }
  return dist[t];
}

int main() {
  int n, k;
  int p;
  cin >> n >> p >> k;

  vector<vector<int> > a(n, vector<int>(n));
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> a[i][j];

  int cnt = 0;
  map<int, int> mp;

  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (cost(a, i, j, INF) <= p) {
        ++cnt;
      } else if (cost(a, i, j, 1) <= p) {
        ++mp[1];
        int l = 1, r = p + 1;
        while (r - l > 1) {
          int m = (l + r) / 2;
          if (cost(a, i, j, m) <= p) l = m;
          else r = m;
        }
        --mp[r];
      }
    }
  }
  if (cnt > k) { cout << "0" << endl; return 0; }
  if (cnt == k) { cout << "Infinity" << endl; return 0; }

  vector<pair<int, int> > vp;
  for (auto m : mp) vp.push_back(m);

  int res = 0;
  for (int i = 0; i < (int)vp.size() - 1; ++i) {
    cnt += vp[i].second;
    if (cnt == k) res = vp[i + 1].first - vp[i].first;
  }
  cout << res << endl;  
  return 0;
}
