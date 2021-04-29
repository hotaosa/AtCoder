#include <iostream>
#include <string>
#include <set>

int main() {
  int n;
  std::cin >> n;
  std::set<std::string> se;
  for (int i = 0; i < n; ++i) {
    std::string s;
    std::cin >> s;
    if (se.find(s) == se.end()) std::cout << i + 1 << std::endl;
    se.insert(s);
  }
  return 0;  
}

