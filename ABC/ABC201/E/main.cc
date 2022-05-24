#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

struct Edge {
  int to;
  long long w;
  Edge(int to_, long long w_) : to(to_), w(w_) { }
};

int main() {
  int n;
  cin >> n;
  vector<vector<Edge> > graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    long long w;
    cin >> u >> v >> w;
    graph[--u].emplace_back(--v, w);
    graph[v].emplace_back(u, w);
  }

  vector<long long> dist(n, -1);
  dist[0] = 0;
  queue<int> que;
  que.push(0);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (auto e : graph[v]) {
      if (dist[e.to] != -1) continue;
      dist[e.to] = dist[v] ^ e.w;
      que.push(e.to);
    }
  }

  vector<vector<mint> > cnt(61, vector<mint>(2, 0));
  for (int i = 0; i < n; ++i) {
    long long d = dist[i];
    for (int j = 0; j <= 60; ++j) {
      ++cnt[j][d & 1];
      d >>= 1;
    }
  }

  vector<mint> pow2(61);
  pow2[0] = 1;
  for (int i = 1; i < 61; ++i) pow2[i] = pow2[i - 1] * 2;

  mint res = 0;  
  for (int i = 0; i <= 60; ++i) {
    res += cnt[i][0] * cnt[i][1] * pow2[i];
  }
  cout << res.val() << endl;
  return 0;
}
