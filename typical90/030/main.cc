#include <iostream>
#include <vector>

int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> cnt(n + 1, 0);
  for (int i = 2; i <= n; ++i) {
    if (cnt[i] > 0) continue;
    for (int j = 1; i * j <= n; ++j) ++cnt[i * j];
  }

  int res = 0;
  for (int i = 2; i <= n; ++i) if (cnt[i] >= k) ++res;
  std::cout << res << std::endl;
  return 0;
}
