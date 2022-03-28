#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1), b(m + 1), c(n + m + 1);
  for (auto &p : a) cin >> p;
  for (auto &p : c) cin >> p;

  for (int i = m; i >= 0; --i) {
    b[i] = c[n + i] / a[n];
    for (int j = 1; j <= n; ++j) {
      c[n + i - j] -= c[n + i] / a[n] * a[n - j];
    }
  }

  for (auto &p : b) cout << p << " ";
  cout << endl;
  return 0;
}
