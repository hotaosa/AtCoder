#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> l(m), r(m);
  vector<long long> c(m);
  for (int i = 0; i < m; ++i) {
    cin >> c[i] >> l[i] >> r[i];
    --l[i];
  }

  vector<int> order(m);
  for (int i = 0; i < m; ++i) order[i] = i;
  sort(order.begin(), order.end(), [&](int i, int j) {
    return c[i] < c[j];
  });

  atcoder::dsu uf(n + 1);
  long long res = 0;
  for (int i : order) {
    if (uf.same(l[i], r[i])) continue;
    uf.merge(l[i], r[i]);
    res += c[i];
  }

  cout << (uf.size(0) == n + 1 ? res : -1) << endl;
  return 0;
}
