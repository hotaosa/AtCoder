#include <iostream>
#include <vector>
#include <set>
#include <map>

int main() {
  int h, w, n;
  std::cin >> h >> w >> n;

  std::vector<std::pair<int, int> > vp;
  std::set<int> se_r, se_c;
  for (int i = 0; i < n; ++i) {
    int a, b;
    std::cin >> a >> b;
    vp.push_back(std::make_pair(a, b));
    se_r.insert(a);
    se_c.insert(b);
  }

  std::map<int, int> ma_r, ma_c;
  int r = 1;
  for (int row : se_r) {
    ma_r[row] = r;
    ++r;
  }
  int c = 1;
  for (int column : se_c) {
    ma_c[column] = c;
    ++c;
  }

  for (int i = 0; i < n; ++i) std::cout << ma_r[vp[i].first] << " " << ma_c[vp[i].second] << std::endl;
  return 0;  
}
