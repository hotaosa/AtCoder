#include <iostream>
#include <vector>
#include <map>

constexpr long long MOD = 998244353LL;

struct BIT {
  int n;
  std::vector<long long> bit;
  BIT(int n_) : n(n_), bit(n + 1, 0) { }
  void add(int i, int x) {
    for (++i; i <= n; i += (i & -i)) bit[i] = (bit[i] + x) % MOD;
  }
  long long sum(int i) {
    long long ret = 0LL;
    for (++i; i > 0; i -= (i & -i)) ret = (ret + bit[i]) % MOD;
    return ret;
  }
};

int comp(std::vector<int> &v) {
  std::map<int, int> mem;
  for (auto p : v) mem[p] = 0;
  int sz = 0;
  for (auto &p : mem) p.second = sz++;
  for (auto &p : v) p = mem[p];
  return sz;
}

long long modpow(long long a, long long n) {
  long long ret = 1LL;
  while (n) {
    if (n & 1) ret = ret * a % MOD;
    a = a * a % MOD;
    n >>= 1;
  }
  return ret;
}

int main() {
  const long long div = modpow(2, MOD - 2);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  int nn = comp(a);
  BIT bit(nn);
  long long res = 0LL;
  for (int i = 0; i < n; ++i) {
    res = (res + bit.sum(a[i]) * modpow(2LL, i)) % MOD;
    bit.add(a[i], modpow(div, i + 1));
  }
  std::cout << res << std::endl;
  return 0;  
}
