#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<vector<int>> graph(n);
  vector<int> deg(n, 0);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    graph[--u].emplace_back(--v);
    graph[v].emplace_back(u);
    ++deg[u];
    ++deg[v];
  }

  vector<bool> is_target(n, false);
  for (int i = 0; i < k; ++i) {
    int v;
    cin >> v;
    is_target[--v] = true;
  }

  queue<int> que;
  for (int i = 0; i < n; ++i) {
    if (deg[i] == 1 && !is_target[i]) {
      que.emplace(i);
    }
  }

  int res = n;
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    --res;
    for (int nv : graph[v]) {
      if (--deg[nv] == 1 && !is_target[nv]) {
        que.emplace(nv);
      }
    }
  }

  cout << res << endl;
  return 0;
}