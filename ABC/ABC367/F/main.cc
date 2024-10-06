#include <iostream>
#include <map>
#include <random>
#include <vector>

int main() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n), b(n);
  for (auto &e : a) std::cin >> e;
  for (auto &e : b) std::cin >> e;

  constexpr long long MOD = (1LL << 61) - 1;
  std::map<int, long long> mp;
  std::random_device seed_gen;
  std::mt19937 rand(seed_gen());

  std::vector<long long> ha(n, 0), hb(n, 0);
  {
    for (int i = 0; i < n; ++i) {
      if (mp.count(a[i])) {
        ha[i] = mp[a[i]];
      } else {
        ha[i] = mp[a[i]] = rand() % MOD;
      }
      if (i > 0) ha[i] = (ha[i] + ha[i - 1]) % MOD;
    }
  }
  {
    for (int i = 0; i < n; ++i) {
      if (mp.count(b[i])) {
        hb[i] = mp[b[i]];
      } else {
        hb[i] = mp[b[i]] = rand() % MOD;
      }
      if (i > 0) hb[i] = (hb[i] + hb[i - 1]) % MOD;
    }
  }

  auto Solve = [&](int la, int ra, int lb, int rb) -> bool {
    long long sa = ha[ra] - (la ? ha[la - 1] : 0);
    long long sb = hb[rb] - (lb ? hb[lb - 1] : 0);
    return sa == sb;
  };

  while (q--) {
    int la, ra, lb, rb;
    std::cin >> la >> ra >> lb >> rb;
    std::cout << (Solve(--la, --ra, --lb, --rb) ? "Yes" : "No") << "\n";
  }

  return 0;
}