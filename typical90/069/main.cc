#include <iostream>
#include <vector>

long long modpow(long long a, long long n, long long mod) {
  long long res = 1LL;
  while (n) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main() {
  const long long MOD = 1000000007LL;
  long long n, k;
  std::cin >> n >> k;

  if (n == 1) { std::cout << k << std::endl; return 0; }
  if (n == 2) { std::cout << k * (k - 1LL) % MOD << std::endl; return 0; }

  long long res = k * (k - 1LL) % MOD;
  n -= 2;
  res = res * modpow(k - 2LL, n, MOD) % MOD;
  std::cout << res << std::endl;
  return 0;                   
}
