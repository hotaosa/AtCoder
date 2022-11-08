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

  if (uf.size(uf.leader(0)) == n) cout << "The graph is connected." << endl;
  else cout << "The graph is not connected." << endl;  
  return 0;
}
