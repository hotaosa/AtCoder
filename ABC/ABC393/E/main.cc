#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> a(n);
  for (auto &e : a) std::cin >> e;

  int siz = *std::max_element(std::begin(a), std::end(a)) + 1;
  std::vector<int> c1(siz, 0), c2(siz, 0), res(siz, 0);
  for (int x : a) ++c1[x];
  for (int i = 1; i < siz; ++i) {
    for (int j = i; j < siz; j += i) {
      c2[i] += c1[j];
    }
  }

  for (int i = 1; i < siz; ++i) {
    if (c2[i] < k) continue;
    for (int j = i; j < siz; j += i) {
      res[j] = std::max(res[j], i);
    }
  }

  for (int x : a) std::cout << res[x] << "\n";
  return 0;
}