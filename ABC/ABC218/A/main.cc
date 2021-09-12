#include <iostream>
#include <string>

int main() {
  int n;
  std::string s;
  std::cin >> n >> s;
  std::cout << (s[n - 1] == 'o' ? "Yes" : "No") << std::endl;
  return 0;
}
