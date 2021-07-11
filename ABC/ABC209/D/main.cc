#include <iostream>
#include <vector>
#include <queue>

int main() {
  int n, q;
  std::cin >> n >> q;
  std::vector<std::vector<int> > graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    std::cin >> a >> b;
    --a;
    --b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  std::vector<int> depth(n, -1);
  depth[0] = 0;
  std::queue<int> que;
  que.push(0);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (int n_v : graph[v]) {
      if (depth[n_v] != -1) continue;
      depth[n_v] = depth[v] + 1;
      que.push(n_v);
    }
  }

  for (int i = 0; i < q; ++i) {
    int c, d;
    std::cin >> c >> d;
    --c;
    --d;
    std::cout << ((depth[c] + depth[d]) & 1 ? "Road" : "Town") << std::endl;
  }
  return 0;  
}
