#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

int main() {
  int n;
  cin >> n;
  
  atcoder::dsu uf(n);
  for (int i = 0; i < n; ++i) {
    int fi;
    cin >> fi;    
    uf.merge(i, --fi);
  }

  mint res = 1;
  for (int i = 0; i < n; ++i) if (uf.leader(i) == i) res *= 2;
  cout << res.val() - 1 << endl;
  return 0;
}
