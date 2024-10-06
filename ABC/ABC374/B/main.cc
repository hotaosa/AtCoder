#include <iostream>
#include <string>

int main() {
  std::string s, t;
  std::cin >> s >> t;

  if (s.size() > t.size()) {
    t += std::string(s.size() - t.size(), '0');
  } else {
    s += std::string(t.size() - s.size(), '0');
  }

  int res = -1;
  for (std::size_t i = 0; i < s.size(); ++i) {
    if (s[i] != t[i]) {
      res = i;
      break;
    }
  }

  std::cout << res + 1 << "\n";
  return 0;
}