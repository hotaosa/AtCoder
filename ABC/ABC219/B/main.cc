#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> vs(3);
  std::string t;
  std::cin >> vs[0] >> vs[1] >> vs[2] >> t;

  std::string res = "";
  for (char c : t) res += vs[c - '1'];
  std::cout << res << std::endl;
  return 0;
}
