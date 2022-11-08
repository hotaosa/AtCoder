#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  double n;
  cin >> n;

  auto judge = [&](double d) -> bool {
    return d * d * d + d < n;
  };

  double l = 0.0, r = 100.1;
  while (r - l > 1.0e-5) {
    double m = (l + r) / 2.0;
    if (judge(m)) l = m;
    else r = m;
  }

  printf("%.5f\n", l);
  return 0;
}
