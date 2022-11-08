#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int op(int a, int b) {
  return max(a, b);
}
int e() {
  return 0;
}

using segtree = atcoder::segtree<int, op, e>;

int vcomp(vector<int> &v) {
  map<int, int> mem;
  for (auto p : v) mem[p] = 0;
  int sz= 0;
  for (auto &p : mem) p.second = sz++;
  for (auto &p : v) p = mem[p];
  return sz;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);  
  for (auto &p : a) cin >> p;
  int size = vcomp(a);
  segtree seg(size + 1);

  for (int i = 0; i < n; ++i) {
    int res = seg.prod(a[i] + 1, size + 1);
    cout << (res > 0 ? res : -1) << endl;
    seg.set(a[i], i + 1);
  }
  
  return 0;
}
