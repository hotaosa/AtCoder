#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }

  vector<vector<int>> graph(n);
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (a[i] == a[j] || b[i] == b[j]) {
        graph[i].emplace_back(j);
        graph[j].emplace_back(i);
      }
    }
  }

  vector<int> dp(1 << n, -1);
  auto Solve = [&](auto Solve, int bit) -> int {
    if (dp[bit] != -1) return dp[bit];
    int turn = (__builtin_popcount(bit) >> 1) & 1;
    for (int i = 0; i < n; ++i) {
      if (bit >> i & 1) continue;
      for (int j : graph[i]) {
        if (bit >> j & 1) continue;
        int nx = Solve(Solve, bit | (1 << i) | (1 << j));
        if (turn && nx == 0) return dp[bit] = 0;
        if (!turn && nx == 1) return dp[bit] = 1;
      }
    }
    return dp[bit] = turn;
  };

  int res = Solve(Solve, 0);
  assert(res != -1);

  cout << (res ? "Takahashi" : "Aoki") << endl;
  return 0;
}