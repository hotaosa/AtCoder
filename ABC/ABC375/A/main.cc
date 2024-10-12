#include <iostream>
#include <string>

int main() {
  std::size_t n;
  std::string s;
  std::cin >> n >> s;

  int res = 0;
  for (std::size_t i = 0; i < n - 1; ++i) {
    if (s.substr(i, 3) == "#.#") ++res;
  }

  std::cout << res << "\n";
  return 0;
}