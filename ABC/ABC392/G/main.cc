#include <iostream>
#include <vector>
//
#include <atcoder/convolution>

int main() {
  constexpr int SIZE = 1000000;
  int n;
  std::cin >> n;
  std::vector<int> p(SIZE, 0);
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    p[--a] = 1;
  }

  long long res = 0;
  auto conv = atcoder::convolution(p, p);
  for (int i = 0; i < SIZE; ++i) {
    if (p[i]) {
      res += (conv[i * 2] - 1) / 2;
    }
  }

  std::cout << res << "\n";
  return 0;
}