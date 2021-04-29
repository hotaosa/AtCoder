#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::pair<int, int>> vp;
  for (int i = 0; i < m; ++i) {
    int a, b;
    std::cin >> a >> b;
    --a; --b;
    vp.push_back(std::make_pair(b, a));
  }
  std::sort(vp.begin(), vp.end());

  int cnt = 0, cur = -1;
  for (int i = 0; i < m; ++i) {
    if (vp[i].second >= cur) {
      ++cnt;
      cur = vp[i].first;
    }
  }

  std::cout << cnt << std::endl;
  return 0;  
}
