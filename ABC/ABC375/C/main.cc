#include <iostream>
#include <string>
#include <vector>

int main() {
  std::size_t n;
  std::cin >> n;

  std::vector<std::string> a(n);
  for (auto &e : a) std::cin >> e;

  for (std::size_t i = 0; i < n; ++i) {
    for (std::size_t j = 0; j < n; ++j) {
      int rot_count =
          (std::min(std::min(i, n - 1 - i), std::min(j, n - 1 - j)) + 1) % 4;

      int r = i, c = j;
      while (rot_count--) {
        int nr = n - 1 - c;
        int nc = r;
        r = nr;
        c = nc;
      }

      std::cout << a[r][c];
    }
    std::cout << "\n";
  }

  return 0;
}