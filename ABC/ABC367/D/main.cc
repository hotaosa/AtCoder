#include <iostream>
#include <map>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  for (auto &e : a) {
    std::cin >> e;
    e %= m;
  }

  for (int i = 0; i < n; ++i) {
    a.emplace_back(a[i]);
  }

  for (int i = 1; i < 2 * n; ++i) {
    a[i] = (a[i] + a[i - 1]) % m;
  }

  std::map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    ++mp[a[i]];
  }

  long long res = 0;
  for (int i = n; i < 2 * n; ++i) {
    --mp[a[i - n]];
    res += mp[a[i]]++;
  }

  std::cout << res << "\n";
  return 0;
}