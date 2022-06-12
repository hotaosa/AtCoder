#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  long long x, a, d, n;
  cin >> x >> a >> d >> n;

  long long res = min(abs(a - x), abs(a + d * (n - 1) - x));
  if (d > 0 && x > a && x < a + d * (n + 1)) {
    long long m = (x - a) % d;
    res = min(res, min(m, d - m));    
  }
  if (d < 0 && x < a && x > a + d * (n + 1)) {
    long long m = (a - x) % d;
    res = min(res, min(m, -d - m));
  }
  cout << res << endl;
  return 0;
}
