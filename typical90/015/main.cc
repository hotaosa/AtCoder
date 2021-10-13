#include <iostream>
#include <vector>

constexpr long long MOD = 1000000007LL;

long long modpow(long long a, long long n) {
  long long ret = 1LL;
  while (n) {
    if (n & 1LL) ret = ret * a % MOD;
    a = a * a % MOD;
    n >>= 1;
  }
  return ret;
}

long long div(long long a, long long b) {
  return a * modpow(b, MOD - 2) % MOD;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<long long> fact(n + 1), fact_inv(n + 1);
  fact[0] = 1LL;
  for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i % MOD;
  for (int i = 0; i <= n; ++i) fact_inv[i] = div(1LL, fact[i]);

  auto comb = [&](int n, int r) -> long long{
    if (r > n || r < 0) return 0LL;
    return fact[n] * fact_inv[r] % MOD * fact_inv[n - r] % MOD;
  };

  auto query = [&](int k) {
    long long ret = 0LL;
    for (int i = 1; i <= n / k + 1; ++i) {
      int s1 = n - (k - 1) * (i - 1);
      int s2 = i;
      ret = (ret + comb(s1, s2)) % MOD;
    }
    return ret;
  };

  for (int k = 1; k <= n; ++k) std::cout << query(k) << std::endl;
  return 0;
}
