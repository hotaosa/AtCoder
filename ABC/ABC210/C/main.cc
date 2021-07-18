#include <iostream>
#include <vector>
#include <map>

int main() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> c(n);
  for (int i = 0; i < n; ++i) std::cin >> c[i];

  int res = 0;
  std::map<int, int> ma;
  for (int i = 0; i < k; ++i) {
    if (++ma[c[i]] == 1) ++res;
  }

  int cur = res;
  for (int i = k; i < n; ++i) {
    if (--ma[c[i - k]] == 0) --cur;
    if (++ma[c[i]] == 1) ++cur;
    res = std::max(res, cur);
  }

  std::cout << res << std::endl;
  return 0;  
}
