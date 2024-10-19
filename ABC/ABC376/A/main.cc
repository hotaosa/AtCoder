#include <iostream>

int main() {
  int n, c;
  std::cin >> n >> c;

  int res = 0, prev = -c;
  for (int i = 0; i < n; ++i) {
    int t;
    std::cin >> t;
    if (t >= prev + c) {
      ++res;
      prev = t;
    }
  }

  std::cout << res << "\n";

  return 0;
}