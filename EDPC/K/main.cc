#include <iostream>
#include <vector>

int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  std::vector<bool> dp(k + 1, false);

  for (int i = 1; i <= k; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i - a[j] >= 0 && !dp[i - a[j]]) dp[i] = true;
    }
  }

  std::cout << (dp[k] ? "First" : "Second") << std::endl;
  return 0;
}
