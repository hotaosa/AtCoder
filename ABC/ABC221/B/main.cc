#include <iostream>
#include <string>

int main() {
  std::string s, t;
  std::cin >> s >> t;

  int len = (int)s.length();
  bool possible = true;
  for (int i = 0; i < len && possible; ++i) {
    if (s[i] == t[i]) continue;
    if (i < len - 1 && s[i] == t[i + 1] && t[i] == s[i + 1]) ++i;
    else possible = false;
  }

  std::cout << (possible ? "Yes" : "No") << std::endl;
  return 0;  
}
