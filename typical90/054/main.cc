#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr int INF = 1 << 30;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int> > graph(n + m);
  for (int i = 0; i < m; ++i) {
    int k;
    cin >> k;
    for (int j = 0; j < k; ++j) {
      int r;
      cin >> r;
      graph[--r].push_back(n + i);
      graph[n + i].push_back(r);
    }
  }

  vector<int> dist(n + m, -2);
  dist[0] = 0;
  queue<int> que;
  que.push(0);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (int nv : graph[v]) {
      if (dist[nv] == -2) {
        dist[nv] = dist[v] + 1;
        que.push(nv);
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << dist[i] / 2 << endl;    
  }  
  return 0;
}
