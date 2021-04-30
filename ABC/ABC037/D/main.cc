#include <iostream>
#include <vector>
#include <algorithm>

using Graph = std::vector<std::vector<int>>;

void rec(const Graph &G, std::vector<bool> &seen, std::vector<int> &order, int v) {
  seen[v] = true;
  for (int n_v : G[v]) {
    if (seen[n_v]) continue;
    rec(G, seen, order, n_v);
  }
  order.push_back(v);
}

int main() {
  const long long MOD = 1000000007LL;
  int h, w;
  std::cin >> h >> w;
  int n = h * w;
  std::vector<std::vector<long long>> a(h, std::vector<long long>(w));
  for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) std::cin >> a[i][j];

  std::vector<int> dr = {1, 0, -1, 0}, dc = {0, 1, 0, -1};
  Graph G(h * w);
  for (int r = 0; r < h; ++r) {
    for (int c = 0; c < w; ++c) {
      for (int i = 0; i < 4; ++i) {
        int n_r = r + dr[i], n_c = c + dc[i];
        if (n_r < 0 || n_r >= h || n_c < 0 || n_c >= w || a[n_r][n_c] <= a[r][c]) continue;
        G[w * r + c].push_back(w * n_r + n_c);
      }
    }
  }

  std::vector<bool> seen(n, false);
  std::vector<int> order;
  for (int v = 0; v < n; ++v) {
    if (seen[v]) continue;
    rec(G, seen, order, v);
  }
  std::reverse(order.begin(), order.end());

  std::vector<long long> dp(n, 1LL);
  long long res = 0LL;
  for (int v : order) {
    res = (res + dp[v]) % MOD;
    for (int n_v : G[v]) dp[n_v] = (dp[n_v] + dp[v]) % MOD;
  }
  std::cout << res << std::endl;
  return 0;
}
