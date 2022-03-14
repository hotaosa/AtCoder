#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

struct Edge {
  int to;
  long long w;
  Edge(int to_, long long w_) : to(to_), w(w_) { }
};

template<class T> inline bool chmin(T &a, T b) {
  if (a >= b) { a = b; return true; }
  return false;
}

int main() {
  int n, m;
  cin >> n >> m;  
  vector<int> a(m), b(m);
  vector<vector<long long> > dist(n, vector<long long>(n, 1LL << 60));
  for (int i = 0; i < m; ++i) {
    long long c;
    cin >> a[i] >> b[i] >> c;    
    dist[a[i]][b[i]] = dist[b[i]][a[i]] = c;
  }

  vector<vector<bool> > update(n, vector<bool>(n, false));
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (k == i || k == j) continue;
        if (chmin(dist[i][j], dist[i][k] + dist[k][j])) update[i][j] = update[j][i] = true;
      }
    }
  }

  int res = 0;
  for (int i = 0; i < m; ++i) if (update[a[i]][b[i]]) ++res;
  cout << res << endl;
  return 0;
}
