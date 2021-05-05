#include <iostream>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> cnt(1001, 0);
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    ++cnt[a];
  }
  for (int i = 0; i < m; ++i) {
    int b;
    std::cin >> b;
    ++cnt[b];
  }
  for (int i = 1; i <= 1000; ++i) if (cnt[i] == 1) std::cout << i << " ";
  std::cout << std::endl;
  return 0;
}
