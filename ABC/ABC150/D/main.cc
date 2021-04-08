#include <bits/stdc++.h>

long long gcd(long long a, long long b) {
  if (b == 0) return a;
  else return gcd(b, a % b);
}

int main () {
  int n;
  long long m;
  std::cin >> n >> m;
  std::vector<long long> a(n);
  for (int i = 0; i < n; ++i) { std::cin >> a[i]; a[i] /= 2LL; }

  bool same = true;
  while (same && !(a[0] & 1)) {
    for (int i = 0; i < n; ++i) {
      if (a[i] & 1) same = false;
      a[i] /= 2LL;
    }
    m /= 2LL;
  }
  if (same) for (int i = 0; i < n; ++i) if (!(a[i] & 1)) same = false;
  if (!same) { std::cout << "0" << std::endl; return 0; }

  long long l = 1LL;
  for (int i = 0; i < n; ++i) l = a[i] / gcd(l, a[i]) * l;

  long long res = (m / l + 1) / 2;
  std::cout << res << std::endl;
  return 0;  
}
