#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr int INF = 1 << 30;

int op(int a, int b) {
  return min(a, b);
}
int e() {
  return INF;
}

using segtree = atcoder::segtree<int, op, e>;

int main() {
  int n, l, r;
  cin >> n >> l >> r;
  vector<int> x(n);
  for (auto &p : x) cin >> p;

  auto range = [&](int i) -> pair<int, int> {
    int pl = lower_bound(x.begin(), x.end(), x[i] - r) - x.begin();
    if (pl == i) return {-1, -1};

    int pr = upper_bound(x.begin(), x.end(), x[i] - l) - x.begin();
    return {pl, pr};
  };

  segtree seg(n);
  seg.set(0, 0);
  for (int i = 1; i < n; ++i) {
    auto [li, ri] = range(i);
    if (li == -1) continue;
    seg.set(i, seg.prod(li, ri) + 1);
  }

  cout << seg.get(n - 1) << endl;  
  return 0;
}
