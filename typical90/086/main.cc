#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> x(q), y(q), z(q);
  vector<long long> w(q);
  for (int i = 0; i < q; ++i) {
    cin >> x[i] >> y[i] >> z[i] >> w[i];
    --x[i]; --y[i]; --z[i];
  }  

  mint res = 1;
  for (int i = 0; i < 60; ++i) {
    mint cur = 0;
    for (int bit = 0; bit < (1 << n); ++bit) {
      bool ok = true;
      for (int j = 0; j < q; ++j) {        
        ok &= ((bit >> x[j] & 1) | (bit >> y[j] & 1) | (bit >> z[j] & 1)) == (w[j] >> i & 1);
      }
      if (ok) ++cur;      
    }
    res *= cur;
  }

  cout << res.val() << endl;  
  return 0;
}
