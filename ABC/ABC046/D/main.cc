#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;

  int res = 0;
  for (int i = 0; i < (int)s.length(); ++i) {
    if (s[i] == 'g') ++res;
    else --res;
  }
  std::cout << res / 2 << std::endl;
  return 0;
}
