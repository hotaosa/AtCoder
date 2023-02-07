#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int op(int a, int b) {
  return a | b;
}
int e() {
  return 0;
}

using segtree = atcoder::segtree<int, op, e>;

int main() {
  int n, q;
  string s;
  cin >> n >> s >> q;

  atcoder::fenwick_tree<int> ft(n);
  segtree seg(n);
  for (int i = 0; i < n; ++i) {
    seg.set(i, 1 << (s[i] - 'a'));
    if (i > 0 && s[i] < s[i - 1]) ft.add(i, 1);
  }

  auto FTSet = [&](int idx, int val) -> void {
    ft.add(idx, val - ft.sum(idx, idx + 1));
  };
  auto SegSet = [&](int idx, char c) -> void {
    seg.set(idx, 1 << (c - 'a'));
  };
  auto Mask = [&](int l, int r) -> int {
    if (l >= r) return 0;
    int ret = (1 << r) - 1;
    ret -= (1 << l) - 1;
    return ret;
  };

  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x;
      char c;
      cin >> x >> c;
      s[--x] = c;
      SegSet(x, c);
      if (x > 0) {
        FTSet(x, s[x] < s[x - 1] ? 1 : 0);
      }
      if (x < n - 1) {
        FTSet(x + 1, s[x + 1] < s[x] ? 1 : 0);
      }
    } else {
      int l, r;
      cin >> l >> r;
      if (l < n && ft.sum(l, r)) {
        cout << "No" << endl;
      } else {
        int cl = s[--l] - 'a' + 1;
        int cr = s[--r] - 'a';
        int prod = seg.prod(0, l) | (r < n - 1 ? seg.prod(r + 1, n) : 0);
        if (prod & Mask(cl, cr)) {
          cout << "No" << endl;
        } else {
          cout << "Yes" << endl;
        }
      }
    }
  }
  
  return 0;
}
