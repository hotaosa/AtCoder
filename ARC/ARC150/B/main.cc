#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;

    int res = 1 << 30;
    int x = 0;
    while (x < res) {
      int r = (b + a + x - 1) / (a + x);
      int y = r * (a + x) - b;
      res = min(res, x + y);
      if (r == 1) break;
      x = (b + r - 2) / (r - 1) - a;
    }

    cout << res << endl;
  }
  
  return 0;
}
