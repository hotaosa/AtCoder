#include <iostream>
#include <vector>

void dfs(const std::vector<std::vector<int> > &graph, std::vector<int> &col, int v) {
  for (int nv : graph[v]) {
    if (col[nv] == -1) {
      col[nv] = 1 - col[v];
      dfs(graph, col, nv);
    }
  }
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int> > graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    std::cin >> a >> b;
    graph[--a].push_back(--b);
    graph[b].push_back(a);
  }

  std::vector<int> col(n, -1);
  col[0] = 0;
  dfs(graph, col, 0);

  int cnt = 0;
  for (int i = 0; i < n; ++i) if(col[i] == 0) ++cnt;
  int flag = (cnt >= n / 2 ? 0 : 1);
  for (int i = 0, c = 0; i < n && c < n / 2; ++i) {
    if (col[i] == flag) {
      std::cout << i + 1 << " ";
      ++c;
    }
  }
  std::cout << std::endl;
  return 0;  
}
