#include <iostream>

long long modpow(long long a, long long n, long long mod) {
  long long res = 1LL;
  while(n) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main() {
  const long long MOD = 1000000007LL;
  int n;
  long long p;
  std::cin >> n >> p;

  long long res = p - 1LL;
  res = res * modpow(p - 2LL, n - 1, MOD) % MOD;
  std::cout << res << std::endl;
  return 0;  
}
