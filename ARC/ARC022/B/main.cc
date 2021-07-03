#include <iostream>
#include <vector>
#include <map>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  std::map<int, int> ma;

  int l = 0, r = 0, res = 0;
  while (r < n) {
    while (ma[a[r]] > 0) {
      --ma[a[l++]];
    }
    ++ma[a[r++]];
    res = std::max(res, r - l);
  }

  std::cout << res << std::endl;
  return 0;  
}
