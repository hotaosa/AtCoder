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
  int l = 0, r = 0, cur = 1;
  ++ma[a[0]];

  while (r < n - 1) {
    while (r < n - 1 && cur <= k) {
      if (++ma[a[++r]] == 1) ++cur;
    }
    if (cur > k) res = std::max(res, r - l);
    else res = std::max(res, r - l + 1);
    while (cur > k) if (--ma[a[l++]] == 0) --cur;    
  }

  std::cout << res << std::endl;  
  return 0;  
}
