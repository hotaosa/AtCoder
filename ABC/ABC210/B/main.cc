#include <iostream>
#include <string>

int main() {
  int n;
  std::string s;
  std::cin >> n >> s;
  int first_bad = -1;
  for (int i = n - 1; i >= 0; --i) if (s[i] == '1') first_bad = i;

  std::cout << (first_bad & 1 ? "Aoki" : "Takahashi") << std::endl;
  return 0;
}
