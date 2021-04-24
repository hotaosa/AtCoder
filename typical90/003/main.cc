#include <iostream>
#include <vector>

bool chmax(int &a, int b) {
  if (a < b) { a = b; return true; }
  return false;
}

void dfs(const std::vector<std::vector<int>> &graph,
         int v, int par, int dis, int &v_s, int &dis_max) {
  if (chmax(dis_max, dis)) v_s = v;
  for (int v_n : graph[v]) {
    if (v_n == par) continue;
    dfs(graph, v_n, v, dis + 1, v_s, dis_max);
  }  
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    std::cin >> a >> b;
    --a; --b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  int v_s = 0, dis_max = 0;
  dfs(graph, 0, -1, 0, v_s, dis_max);
  dfs(graph, v_s, -1, 0, v_s, dis_max);
  std::cout << ++dis_max << std::endl;
  return 0;  
}
