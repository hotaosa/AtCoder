#include <iostream>
#include <string>
#include <map>

int main() {
  int n;
  std::string s;
  std::cin >> n >> s;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    std::map<char, int> ma;
    for (int j = i; j < n; ++j) {
      ++ma[s[j]];
      if (ma['A'] == ma['T'] && ma['G'] == ma['C']) ++res;
    }
  }
  std::cout << res << std::endl;
  return 0;
}
