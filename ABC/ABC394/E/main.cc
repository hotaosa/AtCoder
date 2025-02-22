#include <iostream>
#include <queue>
#include <string>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector graph(n, std::vector(26, std::vector<int>{}));
  std::vector rev(n, std::vector(26, std::vector<int>{}));
  for (int i = 0; i < n; ++i) {
    std::string s;
    std::cin >> s;
    for (int j = 0; j < n; ++j) {
      if (s[j] != '-') {
        graph[i][s[j] - 'a'].emplace_back(j);
        rev[j][s[j] - 'a'].emplace_back(i);
      }
    }
  }

  std::vector dp(n, std::vector<int>(n, -1));
  std::queue<std::pair<int, int>> que;
  for (int i = 0; i < n; ++i) {
    dp[i][i] = 0;
    que.emplace(i, i);
  }

  for (int u = 0; u < n; ++u) {
    for (auto &gui : graph[u]) {
      for (int v : gui) {
        if (u == v) continue;
        que.emplace(u, v);
        dp[u][v] = 1;
      }
    }
  }

  while (!std::empty(que)) {
    auto [u, v] = que.front();
    que.pop();
    for (int i = 0; i < 26; ++i) {
      for (int pu : rev[u][i]) {
        for (int nv : graph[v][i]) {
          if (dp[pu][nv] == -1) {
            dp[pu][nv] = dp[u][v] + 2;
            que.emplace(pu, nv);
          }
        }
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cout << dp[i][j] << (j == n - 1 ? '\n' : ' ');
    }
  }

  return 0;
}