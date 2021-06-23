#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, std::string> > vp;
  for (int i = 0; i < n; ++i) {
    std::string s;
    int t;
    std::cin >> s >> t;
    vp.push_back(std::make_pair(t, s));
  }
  std::sort(vp.begin(), vp.end(), std::greater<std::pair<int, std::string> >());
  std::cout << vp[1].second << std::endl;
  return 0;
}
