#include <iostream>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;
  if (m > 1000) return 0;
  std::vector<std::pair<int, int> > lines(m);
  for (int i = 0; i < m; ++i) std::cin >> lines[i].first >> lines[i].second;

  auto closs = [&](int i, int j) -> bool {
    int l1 = lines[i].first, r1 = lines[i].second;
    int l2 = lines[j].first, r2 = lines[j].second;
    bool ret = l1 < l2 && l2 < r1 && r1 < r2;
    ret |= l2 < l1 && l1 < r2 && r2 < r1;
    return ret;    
  };

  int res = 0;
  for (int i = 0; i < m - 1; ++i) {
    for (int j = i + 1; j < m; ++j) {
      if (closs(i, j)) ++res;
    }
  }

  std::cout << res << std::endl;
  return 0;
}
