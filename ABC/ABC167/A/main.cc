#include <iostream>
#include <string>

int main() {
  std::string s, t;
  std::cin >> s >> t;
  int len = (int)s.length();
  std::cout << (s == t.substr(0, len) ? "Yes" : "No") << std::endl;
  return 0;
}
