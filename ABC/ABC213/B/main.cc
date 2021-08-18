#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int> > vp(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> vp[i].first;
    vp[i].second = i + 1;
  }
  std::sort(vp.begin(), vp.end());
  std::cout << vp[n - 2].second << std::endl;
  return 0;
}
