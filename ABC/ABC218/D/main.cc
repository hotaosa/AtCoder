#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int> > vp;
  std::map<int, std::set<int> > ms;
  for (int i = 0; i < n; ++i) {
    int x, y;
    std::cin >> x >> y;
    vp.push_back(std::make_pair(x, y));
    ms[x].insert(y);
  }
  std::sort(vp.begin(), vp.end());

  int res = 0;
  for (int i = 0; i < n - 1; ++i) {
    int x1 = vp[i].first, y1 = vp[i].second;
    for (int j = i + 1; j < n; ++j) {
      int x2 = vp[j].first, y2 = vp[j].second;
      if (x1 == x2 || y1 == y2 || y1 > y2) continue;
      if (std::binary_search(vp.begin(), vp.end(), std::make_pair(x1, y2)) &&
          std::binary_search(vp.begin(), vp.end(), std::make_pair(x2, y1))) ++res;
    }
  }

  std::cout << res << std::endl;
  return 0;  
}
