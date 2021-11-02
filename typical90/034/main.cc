#include <iostream>
#include <vector>
#include <map>

int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  std::map<int, int> ma;
  int res = 0;
  int cur = 0;
  int left = -1;
  for (int right = 0; right < n; ++right) {
    if (++ma[a[right]] == 1) ++cur;
    if (cur <= k) res = std::max(res, right - left);
    while (cur > k) if (--ma[a[++left]] == 0) --cur;
  }

  std::cout << res << std::endl;
  return 0;  
}
