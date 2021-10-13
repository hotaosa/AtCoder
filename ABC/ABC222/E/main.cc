#include <iostream>
#include <vector>
#include <queue>
#include <map>

struct Edge{
  int id, to;
  Edge(int id_, int to_) : id(id_), to(to_) { }
};

bool dfs(const std::vector<std::vector<Edge> > &graph, int g, int v, int par, std::vector<int> &cnt) {
  if (v == g) return true;
  for (Edge e : graph[v]) {
    if (e.to == par) continue;
    ++cnt[e.id];
    if (dfs(graph, g, e.to, v, cnt)) return true;
    else --cnt[e.id];
  }
  return false;
}

int main() {
  constexpr long long MOD = 998244353LL;
  auto modadd = [&MOD](long long &a, long long b) -> void { a = (a + b) % MOD; };
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int> a(m);
  for (int i = 0; i < m; ++i) { std::cin >> a[i]; --a[i]; }
  
  std::vector<std::vector<Edge> > graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    std::cin >> u >> v;
    graph[--u].push_back(Edge(i, --v));
    graph[v].push_back(Edge(i, u));
  }

  std::vector<int> cnt(n - 1, 0);
  for (int i = 0; i < m - 1; ++i) dfs(graph, a[i + 1], a[i], -1, cnt);

  std::vector<std::map<int, long long> > dp(n + 1);
  dp[0][0] = 1LL;

  for (int i = 0; i < n - 1; ++i) {
    for (auto m : dp[i]) {
      modadd(dp[i + 1][m.first + cnt[i]], m.second);
      modadd(dp[i + 1][m.first - cnt[i]], m.second);
    }
  }
  std::cout << dp[n - 1][k] << std::endl;
  return 0;
}
