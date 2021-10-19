#include <iostream>
#include <vector>
#include <queue>

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int> > graph(n);
  std::vector<int> cnt(n, 0);
  for (int i = 0; i < m; ++i) {
    int a, b;
    std::cin >> a >> b;
    graph[--a].push_back(--b);
    ++cnt[b];
  }

  std::priority_queue<int, std::vector<int>, std::greater<int> > que;
  for (int i = 0; i < n; ++i) if (cnt[i] == 0) que.push(i);
  std::vector<int> res;
  while (!que.empty()) {
    int v = que.top();
    que.pop();
    res.push_back(v);
    for (int nv : graph[v]) if (--cnt[nv] == 0) que.push(nv);
  }

  if ((int)res.size() < n) std::cout << "-1" << std::endl;
  else {
    for (int r : res) std::cout << r + 1 << " ";
    std::cout << std::endl;
  }
  return 0;
}
