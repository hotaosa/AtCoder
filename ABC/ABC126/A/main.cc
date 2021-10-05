#include <iostream>
#include <string>

int main() {
  int n, k;
  std::string s;
  std::cin >> n >> k >> s;

  s[k - 1] = 'a' + (s[k - 1] - 'A');
  std::cout << s << std::endl;
  return 0;
}
