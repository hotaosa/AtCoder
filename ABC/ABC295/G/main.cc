#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);

  int n;
  cin >> n;

  vector<int> p(n, -1);
  for (int i = 1; i < n; ++i) {
    cin >> p[i];
    --p[i];
  }

  atcoder::dsu uf(n);
  vector<int> r(n);
  iota(r.begin(), r.end(), 0);

  auto GetMin = [&](int idx) -> int {
    return r[uf.leader(idx)];
  };

  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      while (GetMin(u) > v) {
        int l = GetMin(u);
        r[uf.merge(l, p[l])] = GetMin(p[l]);
      }
    } else {
      int x;
      cin >> x;
      --x;
      cout << GetMin(x) + 1 << endl;
    }
  }

  return 0;
}
