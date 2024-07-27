#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> l(q), r(q);
  vector<ll> c(q);
  for (int i = 0; i < q; ++i) {
    cin >> l[i] >> r[i] >> c[i];
    --l[i];
    --r[i];
  }

  vector<int> o(q);
  iota(begin(o), end(o), 0);
  sort(begin(o), end(o), [&c](int i, int j) { return c[i] < c[j]; });

  set<int> se;
  for (int i = 0; i < n - 1; ++i) se.insert(i);

  ll res = accumulate(begin(c), end(c), 0LL);
  for (int i : o) {
    while (true) {
      auto it = se.lower_bound(l[i]);
      if (it != end(se) && *it < r[i]) {
        res += c[i];
        se.erase(it);
      } else {
        break;
      }
    }
  }
  if (!se.empty()) res = -1;
  cout << res << endl;
  return 0;
}