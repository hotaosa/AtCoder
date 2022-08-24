#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
  int n, m;
  cin >> n >> m;
  vector<mint> x(n), y(m);
  for (int i = 0; i < n; ++i) {
    int xi;
    cin >> xi;
    x[i] = xi;
  }
  for (int i = 0; i < m; ++i) {
    int yi;
    cin >> yi;
    y[i] = yi;
  }
  
  mint sumx = 0, sumy = 0;
  for (int i = 0; i < n - 1; ++i) sumx += (x[i + 1] - x[i]) * (i + 1) * (n - 1 - i);
  for (int j = 0; j < m - 1; ++j) sumy += (y[j + 1] - y[j]) * (j + 1) * (m - 1 - j);    
  mint res = sumx * sumy;
  cout << res.val() << endl;
  return 0;
}
