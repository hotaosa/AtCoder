#include <iostream>
#include <vector>

inline void ChangeMax(int &a, int b) {
  if (b > a) a = b;
}

int main() {
  int n, x;
  std::cin >> n >> x;

  std::vector<int> v(n), a(n), c(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> v[i] >> a[i] >> c[i];
    --v[i];
  }

  std::vector dp(3, std::vector<int>(x + 1, -1));
  for (int i = 0; i < 3; ++i) dp[i][0] = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = x - c[i]; j >= 0; --j) {
      if (dp[v[i]][j] < 0) continue;
      ChangeMax(dp[v[i]][j + c[i]], dp[v[i]][j] + a[i]);
    }
  }

  for (int i = 0; i < 3; ++i) {
    for (int j = 1; j <= x; ++j) {
      ChangeMax(dp[i][j], dp[i][j - 1]);
    }
  }

  int res = 0;
  for (int i = 0; i <= x; ++i) {
    for (int j = 0; i + j <= x; ++j) {
      int k = x - i - j;
      ChangeMax(res, std::min(dp[0][i], std::min(dp[1][j], dp[2][k])));
    }
  }

  std::cout << res << "\n";
  return 0;
}