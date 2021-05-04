#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;
  int n = (int)s.length();
  int res = 0;
  for (int i = 0; i < n - 3; ++i) if (s.substr(i, 4) == "ZONe") ++res;
  std::cout << res << std::endl;
  return 0;
}
