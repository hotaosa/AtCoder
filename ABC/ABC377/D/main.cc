#include <algorithm>
#include <iostream>
#include <vector>
//
#include <atcoder/segtree>

int Sum(int a, int b) { return a + b; }
int Zero() { return 0; }
bool IsZero(int x) { return x == 0; }

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::pair<int, int>> vp;
  for (int i = 0; i < n; ++i) {
    int l, r;
    std::cin >> l >> r;
    vp.emplace_back(--l, --r);
  }
  std::sort(std::begin(vp), std::end(vp));

  long long res = 0;
  atcoder::segtree<int, Sum, Zero> seg(m);
  for (int l = m - 1; l >= 0; --l) {
    while (!std::empty(vp) && vp.back().first == l) {
      seg.set(vp.back().second, 1);
      vp.pop_back();
    }
    int r = seg.max_right<IsZero>(l);
    res += r - l;
  }

  std::cout << res << "\n";
  return 0;
}
