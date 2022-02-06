#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  atcoder::dsu uf(n + 1);
  while (q--) {
    int l, r;
    cin >> l >> r;
    uf.merge(l - 1, r);
  }

  cout << (uf.same(0, n) ? "Yes" : "No" ) << endl;
  return 0;
}
