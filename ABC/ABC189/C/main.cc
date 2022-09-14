#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &p : a) cin >> p;

  int res = 0;
  for (int i = 0; i < n; ++i) {
    int mn = a[i];
    for (int j = i; j < n; ++j) {
      mn = min(mn, a[j]);
      res = max(res, mn * (j - i + 1));
    }
  }
  cout << res << endl;  
  return 0;
}
