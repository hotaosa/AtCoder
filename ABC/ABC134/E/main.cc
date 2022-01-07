#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int vcomp(vector<int> &v) {
  map<int, int> mem;
  for (auto p : v) mem[p] = 0;
  int sz= 0;
  for (auto &p : mem) p.second = sz++;
  for (auto &p : v) p = mem[p];
  return sz;
}

int op(int a, int b) {
  return max(a, b);
}
int e() {
  return 0;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &p : a) cin >> p;
    int sz = vcomp(a);

    atcoder::segtree<int, op, e> seg(sz);
    for (int i = 0; i < n; ++i) {
        seg.set(a[i], seg.prod(a[i], sz) + 1);
    }

    cout << seg.all_prod() << endl;
    return 0;
}
