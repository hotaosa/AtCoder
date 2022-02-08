#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<long long> > a(n, vector<long long>(n));
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> a[i][j];

  long long res = 0;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {      
      bool eq = false;
      for (int k = 0; k < n; ++k) {
        if (k == i || k == j) continue;
        if (a[i][k] + a[k][j] < a[i][j]) { cout << "-1" << endl; return 0; }
        eq |= a[i][k] + a[k][j] == a[i][j];
      }
      if (!eq) res += a[i][j];
    }
  }
  cout << res << endl;
  return 0;
}
