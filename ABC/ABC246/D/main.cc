#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

long long calc(long long n, long long a) {
  long long l = -1, r = 1000000;
  while (r - l > 1) {
    long long m = (l + r) / 2;
    if (a * a * a + a * a * m + a * m * m + m * m * m >= n) r = m;
    else l = m;
  }
  return r;
}

int main() {
  long long n;
  cin >> n;

  long long res = 1LL << 60;
  for (long long a = 0; a * a * a <= n; ++a) {
    long long b = calc(n, a);
    res = min(res, a * a * a + a * a * b + a * b * b + b * b * b);
  }
  cout << res << endl;
  return 0;
}
