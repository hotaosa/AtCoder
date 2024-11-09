#include <algorithm>
#include <iostream>
#include <numeric>
#include <stack>
#include <vector>
//
#include <atcoder/fenwicktree>
#include <atcoder/segtree>

int Max(int a, int b) { return (a > b) ? a : b; }
int Zero() { return 0; }
using RangeMax = atcoder::segtree<int, Max, Zero>;
using FenwickTree = atcoder::fenwick_tree<int>;

int main() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> h(n), l(q), r(q);
  for (auto &e : h) std::cin >> e;
  for (int i = 0; i < q; ++i) {
    std::cin >> l[i] >> r[i];
    --l[i];
  }

  std::vector<std::size_t> order(q);
  std::iota(std::begin(order), std::end(order), 0);
  std::sort(std::begin(order), std::end(order),
            [&r](auto i, int j) { return r[i] > r[j]; });

  std::stack<int> st;
  RangeMax seg(h);
  FenwickTree fen(n + 1);
  std::vector<int> res(q, 0);

  int i = n - 1;
  for (auto j : order) {
    while (i >= r[j]) {
      while (!std::empty(st) && st.top() < h[i]) {
        fen.add(st.top(), -1);
        st.pop();
      }
      fen.add(h[i], 1);
      st.push(h[i--]);
    }
    res[j] = fen.sum(seg.prod(l[j] + 1, r[j]), n + 1);
  }

  for (auto r : res) std::cout << r << "\n";

  return 0;
}