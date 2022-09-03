#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  int n = h * w;

  auto to_1d = [&](int r, int c) -> int {
    return r * w + c;
  };

  auto next = [&](int v) -> vector<int> {
    vector<int> ret;
    if (v / w > 0) ret.push_back(v - w);
    if (v / w < h - 1) ret.push_back(v + w);
    if (v % w > 0) ret.push_back(v - 1);
    if (v % w < w - 1) ret.push_back(v + 1);
    return ret;
  };

  atcoder::dsu uf(n);
  vector<bool> is_red(n, false);
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int r, c;
      cin >> r >> c;
      int v = to_1d(--r, --c);
      is_red[v] = true;
      auto nx = next(v);
      for (int nv : nx) if (is_red[nv]) uf.merge(v, nv);
    } else {
      int ra, ca, rb, cb;
      cin >> ra >> ca >> rb >> cb;
      int va = to_1d(--ra, --ca);
      int vb = to_1d(--rb, --cb);
      cout << (is_red[va] && uf.same(va, vb) ? "Yes" : "No" ) << endl;
    }
  }  
  return 0;
}
