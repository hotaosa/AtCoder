#include <iostream>
#include <vector>

long long modpow(long long a, long long n, long long mod) {
  long long res = 1LL;
  while (n) {
    if (n & 1LL) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main() {
  const long long MOD = 998244353LL;
  std::vector<long long> fact, fact_inv, inv;

  auto init_comb = [&](int SIZE) -> void {
    fact.resize(SIZE);
    fact_inv.resize(SIZE);
    inv.resize(SIZE);
    fact[0] = fact[1] = fact_inv[0] = fact_inv[1] = inv[1] = 1LL;
    for (int i = 2; i < SIZE; ++i) {
      fact[i] = fact[i - 1] * i % MOD;
      inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
      fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
    }
  };

  auto comb = [&](long long n, long long k) -> long long {
    return fact[n] * (fact_inv[k] * fact_inv[n - k] % MOD) % MOD;
  };

  long long n, m, k;
  std::cin >> n >> m >> k;

  init_comb(n);

  long long res = 0LL;
  for (long long i = 0; i <= k; ++i) {
    long long c = m * modpow(m - 1, n - 1 - i, MOD) % MOD;
    c = c * comb(n - 1, i) % MOD;
    res = (res + c) % MOD;
  }

  std::cout << res << std::endl;
  return 0;
}
