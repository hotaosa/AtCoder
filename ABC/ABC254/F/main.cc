#include <iostream>
#include <vector>
#include <atcoder/segtree>

using namespace std;

int op(int a, int b) {
  return __gcd(a, b);
}
int e() {
  return 0;
}

using segtree = atcoder::segtree<int, op, e>;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n), b(n);
  for (auto &p : a) cin >> p;
  for (auto &p : b) cin >> p;

  segtree seg_a(n), seg_b(n);
  for (int i = 1; i < n; ++i) {
    seg_a.set(i, abs(a[i] - a[i - 1]));
    seg_b.set(i, abs(b[i] - b[i - 1]));
  }

  while (q--) {
    int h1, h2, w1, w2;
    cin >> h1 >> h2 >> w1 >> w2;
    int res = __gcd(seg_a.prod(h1, h2), seg_b.prod(w1, w2));
    cout << __gcd(res, a[h1 - 1] + b[w1 - 1]) << endl;
  }
  return 0;
}