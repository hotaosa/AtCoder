#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  int res = 0;
  atcoder::dsu uf(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    if (uf.same(--u, --v)) ++res;
    uf.merge(u, v);
  }

  cout << res << endl;
  return 0;
}
