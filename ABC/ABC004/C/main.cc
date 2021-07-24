#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  n = n % 30;

  std::vector<int> v = {1, 2, 3, 4, 5, 6};

  for (int i = 0; i < n; ++i) {
    std::swap(v[i % 5], v[i % 5 + 1]);
  }

  for (int res : v) std::cout << res;
  std::cout << std::endl;
  return 0;
}
