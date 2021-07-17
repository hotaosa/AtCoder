#include <iostream>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> cnt(n + 1, 0);
  for (int i = 0; i < m; ++i) {
    int a, b;
    std::cin >> a >> b;
    ++cnt[std::max(a, b)];
  }

  int res = 0;
  for (int c : cnt) if (c == 1) ++res;
  std::cout << res << std::endl;
  return 0;
}
