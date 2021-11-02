#include <iostream>
#include <vector>

int main() {
  int n, k;
  std::cin >> n >> k;

  int res = 0;
  std::vector<int> cnt(n + 1, 0);
  for (int i = 2; i <= n; ++i) {
    if (cnt[i] > 0) continue;
    for (int d = 1; i * d <= n; ++d) {
      if (++cnt[i * d] == k) ++res;
    }
  }
  std::cout << res << std::endl;
  return 0;  
}
