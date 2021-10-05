#include <iostream>
#include <vector>

struct BIT {
  int n;
  std::vector<long long> bit;
  BIT(int n_) : n(n_), bit(n_ + 1, 0LL) { }
  void add(int i, int x) {
    for (++i; i <= n; i += (i & -i)) bit[i] += x;
  }
  long long sum(int i) {
    long long ret = 0LL;
    for (++i; i > 0; i -= (i & -i)) ret += bit[i];
    return ret;
  }
};

int main() {
  constexpr long long MOD = 1000000007LL;
  int n;
  std::cin >> n;
  std::vector<int> v(n);
  for (int i = 0; i < n; ++i) std::cin >> v[i];

  std::vector<long long> fact(n);
  fact[0] = 1LL;
  for (int i = 1; i < n; ++i) fact[i] = fact[i - 1] * i % MOD;

  BIT bit(n);
  long long res = 1LL;
  for (int i = 0; i < n; ++i) {
    res = (res + ((v[i] - 1 - bit.sum(v[i] - 1)) * fact[n - i - 1])) % MOD;
    bit.add(v[i], 1);
  }

  std::cout << res << std::endl;  
  return 0;
}
