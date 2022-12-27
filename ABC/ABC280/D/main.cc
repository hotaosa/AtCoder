#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

map<long long, int> PrimeFactorization(long long num) {
  map<long long, int> ret;
  for (long long i = 2; i * i <= num; ++i) {
    while (num % i == 0) {
      ++ret[i];
      num /= i;
    }
  }
  if (num != 1) ++ret[num];
  return ret;
}

long long Legendre(long long n, long long p) {
  long long ret = 0;
  for (long long d = p; d <= n; d *= p) ret += n / d;
  return ret;
}

int main() {
  long long k;
  cin >> k;

  auto pf = PrimeFactorization(k);

  auto judge = [&](long long n) -> bool {
    for (auto [p, ex] : pf) {
      if (Legendre(n, p) < ex) return false;
    }
    return true;
  };

  long long l = 1, r = k;
  while (r - l > 1) {
    auto m = (l + r) / 2LL;
    if (judge(m)) r = m;
    else l = m;
  }

  cout << r << endl;  
  return 0;
}
