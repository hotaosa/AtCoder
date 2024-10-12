#include <iostream>
#include <numeric>
#include <vector>

inline void ChangeMin(int &a, int b) {
  if (b < a) a = b;
}

int main() {
  std::size_t n;
  std::cin >> n;

  std::vector<int> a(n), b(n);
  for (std::size_t i = 0; i < n; ++i) {
    std::cin >> a[i] >> b[i];
  }

  int sum = std::accumulate(std::begin(b), std::end(b), 0);
  if (sum % 3 != 0) {
    std::cout << "-1\n";
    return 0;
  }

  sum /= 3;
  constexpr int INF = 1 << 30;
  std::vector dp(sum + 1, std::vector<int>(sum + 1, INF));
  dp[0][0] = 0;

  for (std::size_t i = 0; i < n; ++i) {
    std::vector d(sum + 1, std::vector<int>(sum + 1, INF));
    for (int t1 = 0; t1 <= sum; ++t1) {
      for (int t2 = 0; t2 <= sum; ++t2) {
        if (dp[t1][t2] == INF) continue;
        if (t1 + b[i] <= sum) {
          ChangeMin(d[t1 + b[i]][t2], dp[t1][t2] + (a[i] != 1));
        }
        if (t2 + b[i] <= sum) {
          ChangeMin(d[t1][t2 + b[i]], dp[t1][t2] + (a[i] != 2));
        }
        ChangeMin(d[t1][t2], dp[t1][t2] + (a[i] != 3));
      }
    }
    dp = std::move(d);
  }

  int res = dp[sum][sum];
  std::cout << (res < INF ? res : -1) << "\n";
  return 0;
}