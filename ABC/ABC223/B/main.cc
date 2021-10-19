#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;
  int len = (int)s.length();

  std::string mi(len, 'z'), ma(len, 'a');
  for (int i = 0; i < len; ++i) {
    std::string pre = s.substr(i, len - i);
    std::string suf = s.substr(0, i);
    mi = std::min(mi, pre + suf);
    ma = std::max(ma, pre + suf);
  }

  std::cout << mi << std::endl << ma << std::endl;
  return 0;
}
