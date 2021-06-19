#include <iostream>
#include <vector>
#include <algorithm>

void dfs(const std::vector<std::vector<int> > &graph, std::vector<bool> &used,
         std::vector<int> &ord, int v) {
  used[v] = true;
  for (int n_v : graph[v]) {
    if (used[n_v]) continue;
    dfs(graph, used, ord, n_v);
  }
  ord.push_back(v);
}

void dfs(const std::vector<std::vector<int> > &rev, std::vector<bool> &used,
          int v, long long &cnt) {
  ++cnt;
  used[v] = true;
  for (int n_v : rev[v]) {
    if (used[n_v]) continue;
    dfs(rev, used, n_v, cnt);
  }
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

  std::vector<int> ord;
  std::vector<bool> used(n, false);
  for (int v = 0; v < n; ++v) {
    if (used[v]) continue;
    dfs(graph, used, ord, v);
  }

  std::reverse(ord.begin(), ord.end());
  used.assign(n, false);
  long long res = 0LL;
  for (int v : ord) {
    if (used[v]) continue;
    long long cnt = 0LL;
    dfs(rev, used, v, cnt);
    res += cnt * (cnt - 1LL) / 2LL;
  }

  std::cout << res << std::endl;
  return 0;
}
