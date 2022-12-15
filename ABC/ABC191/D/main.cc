#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  long double cx, cy, r;
  cin >> cx >> cy >> r;
  r = nextafter(r, 1.0e+30);

  long long res = 0;
  long long minx = ceil(cx - r), maxx = floor(cx + r);
  for (long long x = minx; x <= maxx; ++x) {
    long double d = sqrtl(r * r - (x - cx) * (x - cx));
    res += floor(cy + d) - ceil(cy - d) + 1;
  }

  cout << res << endl;  
  return 0;
}
