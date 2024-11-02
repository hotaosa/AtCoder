#include <array>
#include <iostream>
#include <numeric>

int main() {
  std::array<int, 4> ar;
  for (int i = 0; i < 4; ++i) {
    int a;
    std::cin >> a;
    ++ar[--a];
  }

  int res = std::accumulate(std::begin(ar), std::end(ar), 0,
                            [](int acc, int a) { return acc + a / 2; });
  std::cout << res << "\n";
  return 0;
}