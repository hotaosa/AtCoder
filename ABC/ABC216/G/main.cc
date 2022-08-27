#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> l(m), r(m), x(m);
  for (int i = 0; i < m; ++i) {
    cin >> l[i] >> r[i] >> x[i];
    --l[i];
  }

  vector<int> order(m);
  for (int i = 0; i < m; ++i) order[i] = i;
  sort(order.begin(), order.end(), [&](const int &lhs, const int &rhs) {
    return r[lhs] < r[rhs];
  });

  set<int> se;
  for (int i = 0; i < n; ++i) se.insert(i);

  vector<int> res(n, 0);
  atcoder::fenwick_tree<int> bit(n);
  for (int i : order) {
    int need = x[i] - bit.sum(l[i], r[i]);    
    while (need > 0) {
      auto p = se.lower_bound(r[i]);
      --p;
      se.erase(p);
      res[*p] = 1;
      bit.add(*p, 1);
      --need;
    }
  }

  for (auto r : res) cout << r << " ";
  cout << endl;
  return 0;
}
