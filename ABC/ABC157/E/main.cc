#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int op(int a, int b) {
  return a | b;
}
int e() {
  return 0;
}

int main() {
  int n, q;
  string s;
  cin >> n >> s >> q;

  atcoder::segtree<int, op, e> seg(n);
  for (int i = 0; i < n; ++i) seg.set(i, 1 << (s[i] - 'a'));

  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int p;
      char c;
      cin >> p >> c;
      seg.set(--p, 1 << (c - 'a'));
    } else {
      int l, r;
      cin >> l >> r;      
      cout << __builtin_popcount(seg.prod(--l, r)) << endl;      
    }
  }
  return 0;
}
