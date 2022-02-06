#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<map<int, int> > vm(n);
  for (int i = 0; i < n; ++i) {
    int c;
    cin >> c;
    ++vm[i][--c];
  }

  atcoder::dsu uf(n);
  while (q--) {
    int t, a, b;
    cin >> t >> a >> b;
    --a;
    --b;
    if (t == 1) {
      a = uf.leader(a);
      b = uf.leader(b);
      if (uf.same(a, b)) continue;
      uf.merge(a, b);
      if (uf.leader(a) != a) swap(a, b);
      for (auto m : vm[b]) vm[a][m.first] += m.second;
    } else {
      cout << vm[uf.leader(a)][b] << endl;
    }
  }
  return 0;
}
