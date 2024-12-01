#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
//
#include <atcoder/lazysegtree>

int Max(int a, int b) { return std::max(a, b); }
int Zero() { return 0; }
int Update(int f, int x) { return f > 0 ? f : x; }
int Merge(int f, int g) { return f > 0 ? f : g; }
using LazySegtree =
    atcoder::lazy_segtree<int, Max, Zero, int, Update, Merge, Zero>;

int main() {
  int h, w, n;
  std::cin >> h >> w >> n;

  std::vector<int> row(n), left(n), right(n);
  for (int i = 0; i < n; ++i) {
    int width;
    std::cin >> row[i] >> left[i] >> width;
    right[i] = --left[i] + width;
  }

  std::vector<int> order(n);
  std::iota(std::begin(order), std::end(order), 0);
  std::sort(std::begin(order), std::end(order),
            [&row](int i, int j) { return row[i] > row[j]; });

  LazySegtree seg(std::vector<int>(w, 0));
  std::vector<int> res(n);
  for (int i : order) {
    int prod = seg.prod(left[i], right[i]);
    res[i] = h - prod;
    seg.apply(left[i], right[i], prod + 1);
  }

  for (int r : res) {
    std::cout << r << "\n";
  }

  return 0;
}