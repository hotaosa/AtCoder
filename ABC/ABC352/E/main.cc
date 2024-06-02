#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
//
#include <atcoder/dsu>

using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;

  vector<ll> c(m);
  vector<vector<int>> a(m);
  for (int i = 0; i < m; ++i) {
    int k;
    cin >> k >> c[i];
    while (k--) {
      int x;
      cin >> x;
      a[i].emplace_back(--x);
    }
  }

  vector<int> order(m);
  iota(begin(order), end(order), 0);
  sort(begin(order), end(order), [&](int i, int j) { return c[i] < c[j]; });

  atcoder::dsu uf(n);
  ll res = 0;
  for (int i : order) {
    for (int j = 1; j < (int)size(a[i]); ++j) {
      if (!uf.same(a[i][j], a[i][j - 1])) {
        res += c[i];
        uf.merge(a[i][j], a[i][j - 1]);
      }
    }
  }

  if (uf.size(0) < n) {
    res = -1;
  }

  cout << res << endl;
  return 0;
}