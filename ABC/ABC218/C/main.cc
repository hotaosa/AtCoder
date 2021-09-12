#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int> > s, t;
  for (int i = 0; i < n; ++i) {
    std::string ss;
    std::cin >> ss;
    for (int j = 0; j < n; ++j) if (ss[j] == '#') s.push_back(std::make_pair(i, j));
  }
  for (int i = 0; i < n; ++i) {
    std::string tt;
    std::cin >> tt;
    for (int j = 0; j < n; ++j) if (tt[j] == '#') t.push_back(std::make_pair(i, j));
  }

  if (s.size() != t.size()) {
      std::cout << "No" << std::endl;
      return 0;
  }

  auto rotate = [&]() -> void {
    for (int i = 0; i < (int)s.size(); ++i) {
      s[i] = std::make_pair(s[i].second, n - 1 - s[i].first);
    }
    std::sort(s.begin(), s.end());
  };

  auto judge = [&]() -> bool {
    for (int i = 1; i < (int)s.size(); ++i) {
      if (s[i].first - s[i - 1].first != t[i].first - t[i - 1].first) return false;
      if (s[i].second - s[i - 1].second != t[i].second - t[i - 1].second) return false;      
    }
    return true;
  };

  for (int i = 0; i < 4; ++i) {
    rotate();
    if (judge()) {
      std::cout << "Yes" << std::endl;
      return 0;
    }
  }
  std::cout << "No" << std::endl;
  return 0;    
}
