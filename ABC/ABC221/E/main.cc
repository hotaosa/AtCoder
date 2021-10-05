#include <iostream>
#include <vector>
#include <map>

constexpr long long MOD = 998244353LL;

long long modadd(long long a, long long b) { return (a + b) % MOD; }
long long modpow(long long a, long long n) {
  long long ret = 1LL;
  while (n) {
    if (n & 1) ret = ret * a % MOD;
    a = a * a % MOD;
    n >>= 1;
  }
  return ret;
}

int comp(std::vector<int> &v) {
  std::map<int, int> mem;
  for (auto p : v) mem[p] = 0;
  int sz = 0;
  for (auto &p : mem) p.second = sz++;
  for (auto &p : v) p = mem[p];
  return sz;
}

struct BIT {
  int n;
  std::vector<long long> bit;
  BIT(int n_) : n(n_), bit(n_ + 1, 0LL) { }
  void add(int i, long long x) {
    for (++i; i <= n; i += (i & -i)) bit[i] = modadd(bit[i], x);
  }
  long long sum(int i) {
    long long ret = 0LL;
    for (++i; i > 0; i -= (i & -i)) ret = modadd(ret, bit[i]);
    return ret;
  }
};

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  std::vector<long long> pw(n), pwinv(n);
  pw[0] = 1LL;
  pwinv[0] = modpow(2LL, MOD - 2LL);
  for (int i = 1; i < n; ++i) {
    pw[i] = pw[i - 1] * 2LL % MOD;
    pwinv[i] = pwinv[i - 1] * pwinv[0] % MOD;
  }

  BIT bit(comp(a));
  long long res = 0LL;
  for (int i = 0; i < n; ++i) {
    res = modadd(res, pw[i] * bit.sum(a[i]));
    bit.add(a[i], pwinv[i]);
  }
  std::cout << res << std::endl;
  return 0;
}
