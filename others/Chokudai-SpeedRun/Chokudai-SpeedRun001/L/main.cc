#include <iostream>
#include <vector>
#include <map>

struct BIT {
  int n;
  std::vector<long long> bit;
  BIT(int n_) : n(n_), bit(n + 1, 0LL) { }
  void add(int i, long long x) {
    for (++i; i <= n; i += (i & -i)) bit[i] += x;
  }
  long long sum(int i) {
    long long ret = 0LL;
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
  std::vector<int> v(n), pos(n);
  for (int i = 0; i < n; ++i) std::cin >> v[i];
  comp(v);
  for (int i = 0; i < n; ++i) pos[v[i]] = i;

  int swap = 0;
  for (int i = 0; i < n; ++i) {
    if (v[i] != i) {
      ++swap;
      int id = pos[i];
      pos[v[i]] = id;
      std::swap(v[i], v[id]);
    }
  }

  std::cout << ((n - swap) & 1 ? "NO" : "YES") << std::endl;
  return 0;
}
