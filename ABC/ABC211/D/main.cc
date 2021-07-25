#include <iostream>
#include <vector>
#include <queue>

int main() {
  const long long MOD = 1000000007LL;
  
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int> > graph(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    std::cin >> a >> b;
    graph[--a].push_back(--b);
    graph[b].push_back(a);
  }

  std::vector<int> dist(n, -1);
  std::vector<long long> cnt(n, 0LL);
  std::queue<int> que;
  que.push(0);
  dist[0] = 0;
  cnt[0] = 1LL;

  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (int nv : graph[v]) {
      if (dist[nv] == -1) {
        dist[nv] = dist[v] + 1;
        que.push(nv);
      }
      if (dist[nv] == dist[v] + 1) cnt[nv] = (cnt[nv] + cnt[v]) % MOD;
    }
  }

  std::cout << cnt[n - 1] << std::endl;
  return 0;  
}
