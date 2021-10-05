#include <iostream>
#include <vector>
#include <map>

struct BIT {
  int n;
  std::vector<long long> bit;
  BIT(int n_) : n(n_), bit(n_ + 1, 0LL) { }
  void add(int i, int x) {
    for (++i; i <= n; i += (i & -i)) bit[i] += x;
  }
  long long sum(int i) {
    long long ret = 0;
    for (++i; i > 0; i -= (i & -i)) ret += bit[i];
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

int main() {
  int n;
  std::cin >> n;
  std::vector<int> v(n);
  for (int i = 0; i < n; ++i) std::cin >> v[i];

  int nn = comp(v);
  BIT bit(nn);
  long long res = 0LL;
  for (int i = 0; i < n; ++i) {
    res += (i - bit.sum(v[i]));
    bit.add(v[i], 1);
  }
  std::cout << res << std::endl;
  return 0;  
}
