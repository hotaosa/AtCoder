#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int> > sum(2, vector<int>(n + 1, 0));
  for (int i = 1; i <= n; ++i) {
    int c, p;
    cin >> c >> p;
    sum[--c][i] = p;
  }
  for (int i = 0; i < 2; ++i) for (int j = 1; j <= n; ++j) sum[i][j] += sum[i][j - 1];

  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l;
    for (int i = 0; i < 2; ++i) cout << sum[i][r] - sum[i][l] << " ";
    cout << endl;
  }
  
  return 0;
}
