#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m, e;
  cin >> n >> m >> e;
  
  vector<pair<int, int> > vp(e);
  for (int i = 0; i < e; ++i) {
    int u, v;
    cin >> u >> v;
    vp[i] = {--u, --v};
  }

  int q;
  cin >> q;
  vector<int> x(q);
  vector<bool> is_active(e, true);
  for (int i = 0; i < q; ++i) {
    cin >> x[i];
    is_active[--x[i]] = false;
  }

  atcoder::dsu uf(n + m + 1);
  for (int i = n; i < n + m; ++i) uf.merge(i, n + m);

  for (int i = 0; i < e; ++i) {
    if (is_active[i]) {
      uf.merge(vp[i].first, vp[i].second);
    }
  }

  vector<int> res(q);
  for (int i = q - 1; i >= 0; --i) {
    res[i] = uf.size(n + m) - m - 1;
    uf.merge(vp[x[i]].first, vp[x[i]].second);
  }

  for (int r : res) cout << r << endl;
  return 0;
}
