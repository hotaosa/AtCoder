#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr int INF = 1 << 30;

struct Edge {
  int src, to;
  int w;
  Edge(int src_, int to_, int w_) : src(src_), to(to_), w(w_) { }
  Edge(int to_, int w_) : src(-1), to(to_), w(w_) { }
  Edge(int to_) : src(-1), to(to_), w(1) { }
  bool operator<(const Edge other) const { return w < other.w; }
};

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) { a = b; return true; }
  return false;
}

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

int main() {
  int n, m, l;
  cin >> n >> m >> l;
  vector<vector<Edge> > graph(n);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    if (c <= l) {
      graph[--a].emplace_back(--b, c);
      graph[b].emplace_back(a, c);
    }
  }  

  vector<vector<vector<int> > > dp(n, vector<vector<int> > (n, vector<int>(n, -1)));
  vector<vector<int> > res(n, vector<int>(n, INF));
  for (int s = 0; s < n; ++s) {
    dp[s][s][0] = l;        
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> > > pque;
    pque.emplace(l, s, 0);
    while (!pque.empty()) {
      int f = get<0>(pque.top());
      int v = get<1>(pque.top());
      int ch = get<2>(pque.top());
      pque.pop();      
      if (f < dp[s][v][ch]) continue;      
      for (auto e : graph[v]) {
        if (ch > min(res[s][e.to] + 1, n - 2)) continue;
        if (f >= e.w) {
          chmin(res[s][e.to], ch);
          if (chmax(dp[s][e.to][ch], f - e.w)) pque.emplace(f - e.w, e.to, ch);
        } else {
          chmin(res[s][e.to], ch + 1);
          if (chmax(dp[s][e.to][ch + 1], l - e.w)) pque.emplace(l - e.w, e.to, ch + 1);
        }
      }
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int s, t;
    cin >> s >> t;
    --s; --t;
    cout << (res[s][t] < INF ? res[s][t] : -1) << endl;
  }
  return 0;
}
