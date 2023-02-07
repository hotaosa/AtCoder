#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, p, q, r, s;
  cin >> n >> p >> q >> r >> s;
  --p; --r;
  vector<int> a(n);
  for (auto &p : a) cin >> p;

  vector<int> b(n);
  for (int i = 0; i < p; ++i) b[i] = a[i];
  for (int i = p; i < q; ++i) b[i] = a[i + r - p];
  for (int i = q; i < r; ++i) b[i] = a[i];
  for (int i = r; i < s; ++i) b[i] = a[i - r + p];
  for (int i = s; i < n; ++i) b[i] = a[i];

  for (auto r : b) cout << r << " ";
  cout << endl;  
  return 0;
}
