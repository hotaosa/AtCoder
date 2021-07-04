#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;
  for (int i = (int)s.length() - 1; i >= 0; --i) {
    if (s[i] == '6') s[i] = '9';
    else if (s[i] == '9') s[i] = '6';
    std::cout << s[i];
  }
  std::cout << std::endl;
  return 0;  
}
