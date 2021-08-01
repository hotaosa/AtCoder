#include <iostream>
#include <vector>
#include <string>

int main() {
  std::string s;
  std::cin >> s;
  std::vector<int> num(4);
  for (int i = 0; i < 4; ++i) num[i] = s[i] - '0';

  bool all_same = true;
  bool all_step = true;
  for (int i = 1; i < 4; ++i) {
    if (num[i] != num[i - 1]) all_same = false;
    if (num[i] != (num[i - 1] + 1) % 10) all_step = false;
  }

  std::cout << (all_same || all_step ? "Weak" : "Strong") << std::endl;
  return 0;    
}
