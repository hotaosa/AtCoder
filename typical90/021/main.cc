#include <iostream>
#include <vector>

void dfs(const std::vector<std::vector<int> > &graph, std::vector<int> &order, std::vector<bool> &seen, int v) {
  seen[v] = true;
  for (int nv : graph[v]) if (!seen[nv]) dfs(graph, order, seen, nv);
  order.push_back(v);
}

void dfs2(const std::vector<std::vector<int> > &rev, std::vector<bool> &seen, long long &cnt, int v) {
  seen[v] = true;
  ++cnt;
  for (int nv : rev[v]) if (!seen[nv]) dfs2(rev, seen, cnt, nv);
}

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int> > graph(n), rev(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    std::cin >> a >> b;
    graph[--a].push_back(--b);
    rev[b].push_back(a);
  }

  std::vector<int> order;
  std::vector<bool> seen(n, false);
  for (int i = 0; i < n; ++i) if (!seen[i]) dfs(graph, order, seen, i);

  long long res = 0LL;
  seen.assign(n, false);
  for (int i = n - 1; i >= 0; --i) {
    int v = order[i];
    if (!seen[v]) {
      long long cnt = 0LL;
      dfs2(rev, seen, cnt, v);
      res += cnt * (cnt - 1LL) / 2LL;
    }
  }

  std::cout << res << std::endl;
  return 0;
}
