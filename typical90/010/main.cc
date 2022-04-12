#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int> > sum(n, vector<int>(2, 0));
  for (int i = 0; i < n; ++i) {
    if (i > 0) sum[i] = sum[i - 1];
    int c, p;
    cin >> c >> p;
    sum[i][--c] += p;        
  }

  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    --r;
    --l;
    if (l == 0) cout << sum[r][0] << " " << sum[r][1] << endl;
    else cout << sum[r][0] - sum[l - 1][0] << " " << sum[r][1] - sum[l - 1][1] << endl;
  }
  return 0;
}
