#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;
  std::cout << (s.ends_with("san") ? "Yes" : "No") << "\n";
  return 0;
}