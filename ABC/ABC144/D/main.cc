#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  double a, b, x;
  cin >> a >> b >> x;
  if (x / a / a >= b / 2.0) printf("%.10f\n", 180.0 / M_PI * atan(2.0 / a * (b - x / a / a)));
  else printf("%.10f\n", 180.0 / M_PI * atan(a * b * b / 2.0 / x));
  return 0;
}
