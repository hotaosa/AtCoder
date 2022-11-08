#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  atcoder::dsu uf(n);
  while (q--) {
    int t, u, v;
    cin >> t >> u >> v;
    if (t == 1) uf.merge(--u, --v);
    else cout << (uf.same(--u, --v) ? "Yes" : "No" ) << endl;    
  }
  
  return 0;
}
