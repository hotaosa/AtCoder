#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  atcoder::dsu uf(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    uf.merge(--u, --v);
  }

  int res = 0;
  for (int i = 0; i < n; ++i) {
    res += uf.leader(i) == i;
  }

  cout << res << endl;  
  return 0;
}
