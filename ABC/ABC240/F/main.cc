#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr long long INF = 1LL << 60;

long long func(long long x, long long b, long long m) {
  return b * m + (m + 1) * m / 2 * x;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long res = -INF;
    long long b = 0, c = 0;
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i) {
      long long x, y;
      cin >> x >> y;

      int l = 0, r = y;
      while (r - l > 2) {
        int m1 = (l + r) / 2;
        int m2 = m1 + 1;
        if (func(x, b, m1) < func(x, b, m2)) l = m1;
        else r = m2;
      }
      res = max(res, c + func(x, b, l + 1));

      c += func(x, b, y);
      b += x * y;
      res = max(res, c);
    }
    cout << res << endl;
  }
  return 0;
}
