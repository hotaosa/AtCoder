#include <iostream>
#include <numeric>
#include <vector>
//
#include <atcoder/convolution>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> s(n);
  for (auto &e : s) std::cin >> e;

  const std::size_t siz = *max_element(s.begin(), s.end()) + 1;
  std::vector<int> p(siz, 0);
  for (int x : s) p[x] = 1;

  const auto conv = atcoder::convolution(p, p);
  long long res = 0;
  for (std::size_t i = 0; i < siz; ++i) {
    if (p[i]) res += (conv[i * 2] - 1) >> 1;
  }

  std::cout << res << "\n";
  return 0;
}