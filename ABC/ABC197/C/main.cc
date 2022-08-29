#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &p : a) cin >> p;

  int res = 1 << 30;
  for (int bit = 0; bit < (1 << (n - 1)); ++bit) {
    int xsum = 0;
    int cur_or = 0;
    for (int i = 0; i < n; ++i) {
      cur_or |= a[i];
      if (bit & (1 << i)) {
        xsum ^= cur_or;
        cur_or = 0;
      }
    }
    xsum ^= cur_or;
    res = min(res, xsum);
  }
  cout << res << endl;  
  return 0;
}
