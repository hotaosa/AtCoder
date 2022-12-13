#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  long long a, b;
  cin >> a >> b;

  auto func = [&](long long k) -> double {
    return a / sqrt(k + 1) + (double)b * k;
  };

  long long l = 0, r = 1LL << 60;
  while (r - l > 2) {
    long long m1 = l + (r - l) / 3;
    long long m2 = r - (r - l) / 3;
    if (func(m1) < func(m2)) r = m2;
    else l = m1;
  }

  double res = 1.0e30;
  for (long long k = l; k <= r; ++k) res = min(res, func(k));
  printf("%.10f\n", res);
  return 0;
}
