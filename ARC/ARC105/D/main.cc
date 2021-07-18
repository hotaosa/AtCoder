#include <iostream>
#include <map>

int main() {
  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    int n;
    std::cin >> n;
    std::map<int, int> ma;
    for (int i = 0; i < n; ++i) {
      int a;
      std::cin >> a;
      ++ma[a];
    }
    if (n & 1) std::cout << "Second" << std::endl;
    else {
      bool exist_odd = false;
      for (auto m : ma) if (m.second & 1) exist_odd = true;
      std::cout << (exist_odd ? "First" : "Second") << std::endl;
    }
  }
  return 0;
}
