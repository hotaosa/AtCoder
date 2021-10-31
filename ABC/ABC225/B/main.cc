#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> cnt(n, 0);
  int ma = 0;
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    std::cin >> a >> b;
    ma = std::max(ma, ++cnt[--a]);
    ma = std::max(ma, ++cnt[--b]);
  }
  std::cout << (ma == n - 1 ? "Yes" : "No") << std::endl;
  return 0;
}
