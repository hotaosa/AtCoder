#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) { a = b; return true; }
  return false;
}

int tree_diameter(const vector<vector<int> > &graph) {
  int n = graph.size();
  pair<int, int> far_v = {0, 0};

  auto bfs = [&](int s) -> std::vector<int> {
    std::vector<int> dist(n, -1);
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
          chmax(far_v, {dist[nv], nv});          
        }
      }
    }
    return dist;    
  };

  std::vector<int> d = bfs(0);
  d.clear();
  d = bfs(far_v.second);
  return far_v.first;  
}

int main() {
  int n;
  cin >> n;
  vector<vector<int> > graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    graph[--u].push_back(--v);
    graph[v].push_back(u);
  }
  cout << tree_diameter(graph) + 1 << endl;
  return 0;
}
