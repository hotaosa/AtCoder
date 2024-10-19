#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> a(n), b(n - 1);
  for (auto &e : a) std::cin >> e;
  for (auto &e : b) std::cin >> e;
  std::sort(std::rbegin(a), std::rend(a));
  std::multiset<int> ms(std::begin(b), std::end(b));

  int res = 0;
  for (int x : a) {
    auto it = ms.lower_bound(x);
    if (it == std::end(ms)) {
      if (res) {
        std::cout << "-1\n";
        return 0;
      }
      res = x;
    } else {
      ms.erase(it);
    }
  }

  std::cout << res << "\n";
  return 0;
}