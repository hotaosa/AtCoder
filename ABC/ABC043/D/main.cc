#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;
  int n = (int)s.length();  

  int l = -1, r = -1;
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] == s[i + 1]) {
      l = i + 1;
      r = i + 2;
      break;
    }
    if (i < n - 2 && s[i] == s[i + 2]) {
      l = i + 1;
      r = i + 3;
      break;
    }
  }
  std::cout << l << " " << r << std::endl;
  return 0;
}
