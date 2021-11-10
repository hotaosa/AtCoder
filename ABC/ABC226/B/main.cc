#include <iostream>
#include <vector>
#include <set>

int main() {
  int n;
  std::cin >> n;
  std::set<std::vector<int> > se;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    int l;
    std::cin >> l;
    std::vector<int> a(l);
    for (int j = 0; j < l; ++j) std::cin >> a[j];
    if (se.insert(a).second) ++res;
  }
  std::cout << res << std::endl;
  return 0;
}
