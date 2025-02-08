#include <iostream>
#include <vector>
//
#include <atcoder/segtree>

int Add(int a, int b) { return a + b; }
int Zero() { return 0; }
using Segtree = atcoder::segtree<int, Add, Zero>;

struct MaxRight {
  int value;
  bool operator()(int x) { return x < value; }
};

int main() {
  int n;
  std::cin >> n;
  std::vector<int> p(n);
  for (auto &e : p) std::cin >> e;

  std::vector<int> res(n);
  Segtree seg{std::vector<int>(n, 1)};
  for (int i = n - 1; i >= 0; --i) {
    int idx = seg.max_right<MaxRight>(0, MaxRight(p[i]));
    res[idx] = i;
    seg.set(idx, 0);
  }

  for (int r : res) std::cout << r + 1 << "\n";
  return 0;
}