#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  double a, b, c, x;
  cin >> a >> b >> c >> x;
  double res = 1.0;
  if (x > a) {
    if (x > b) res = 0.0;
    else res = c / (b - a);
  }
  printf("%.7f\n", res);
  return 0;
}
