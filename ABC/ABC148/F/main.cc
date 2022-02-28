#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

vector<int> bfs(const vector<vector<int> > &graph, int s) {
  int n = graph.size();
  vector<int> dist(n, -1);
  dist[s] = 0;
  queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (int nv : graph[v]) {
      if (dist[nv] == -1) {
        dist[nv] = dist[v] + 1;
        que.push(nv);
      }
    }
  }
  return dist;
}

int main() {
  int n, u, v;
  cin >> n >> u >> v;
  --u;
  --v;

  vector<vector<int> > graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    graph[--a].push_back(--b);
    graph[b].push_back(a);
  }
  
  vector<int> dist_t = bfs(graph, u);
  vector<int> dist_a = bfs(graph, v);

  int res = dist_a[u] - 1;
  vector<bool> used(n, false);
  used[u] = true;
  queue<int> que;
  que.push(u);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (int nv : graph[v]) {
      if (used[nv]) continue;
      used[nv] = true;
      if (dist_t[nv] > dist_a[nv]) continue;
      else if (dist_t[nv] == dist_a[nv]) res = max(res, dist_t[nv]);
      else {        
        res = max(res, dist_a[nv] - 1);
        que.push(nv);
      }      
    }
  }
  cout << res << endl;  
  return 0;
}
