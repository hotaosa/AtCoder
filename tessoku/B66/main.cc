#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(m), b(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i] >> b[i];
    --a[i]; --b[i];
  }

  int q;
  cin >> q;
  vector<bool> is_active(m, true);
  vector<int> t(q), x(q), y(q);
  for (int i = 0; i < q; ++i) {
    cin >> t[i] >> x[i];
    --x[i];
    if (t[i] == 1) {
      is_active[x[i]] = false;
    } else {      
      cin >> y[i];
      --y[i];
    }
  }

  atcoder::dsu uf(n);
  for (int i = 0; i < m; ++i) if (is_active[i]) uf.merge(a[i], b[i]);

  vector<string> res;
  for (int i = q - 1; i >= 0; --i) {
    if (t[i] == 1) uf.merge(a[x[i]], b[x[i]]);
    else res.push_back(uf.same(x[i], y[i]) ? "Yes" : "No");
  }

  for (auto it = res.rbegin(); it != res.rend(); ++it) cout << *it << endl;     
  return 0;
}
