#include <iostream>
#include <string>

int main() {
  std::string res = "";
  for (int i = 0; i < 26; ++i) {
    int p;
    std::cin >> p;
    --p;
    res += 'a' + p;
  }
  std::cout << res << std::endl;
  return 0;
}
