#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int> > a(n, vector<int>(n));
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> a[i][j];

  vector<int> row(n);
  iota(row.begin(), row.end(), 0);

  int q;
  cin >> q;
  while (q--) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) swap(row[--x], row[--y]);
    else cout << a[row[--x]][--y] << endl;
  }
  
  return 0;
}
