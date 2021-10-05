#include <iostream>
#include <vector>

constexpr long long MOD = 1000000007LL;

long long modpow(long long a, long long n) {
  long long ret = 1LL;
  while (n) {
    if (n & 1) ret = ret * a % MOD;
    a = a * a % MOD;
    n >>= 1;
  }
  return ret;
}

long long fact(long long n) {
  long long ret = 1LL;
  for (long long i = 2LL; i <= n; ++i) {
    ret = ret * i % MOD;
  }
  return ret;
}

long long factinv(long long n) {
  long long ret = 1LL;
  for (long long i = 2LL; i <= n; ++i) {
    ret = ret * modpow(i, MOD - 2) % MOD;
  }
  return ret;
}

long long comb(long long n, long long k) {
  return fact(n) * factinv(k) % MOD * factinv(n - k) % MOD;
}

int main() {
  int h, w, k;
  std::cin >> h >> w >> k;

  const long long base = comb(h * w - 2, k - 2);
  long long res = 0LL;
  for (int d = 1; d < w; ++d) {
    res = (res + d * base % MOD * (w - d) % MOD * h % MOD * h) % MOD;
  }
  for (int d = 1; d < h; ++d) {
    res = (res + d * base % MOD * (h - d) % MOD * w % MOD * w) % MOD;
  }
  std::cout << res << std::endl;
  return 0;
}
