#include <iostream>
#include <string>

bool exist(int num, int i) {
  for (int j = 0; j < 4; ++j) {
    if (num % 10 == i) return true;
    num /= 10;
  }
  return false;
}

int main() {
  std::string s;
  std::cin >> s;

  int res = 0;
  for (int num = 0; num < 10000; ++num) {
    bool possible = true;
    for (int i = 0; i < 10; ++i) {
      if (s[i] == 'o' && !exist(num, i))  possible = false;
      if (s[i] == 'x' && exist(num, i)) possible = false;
    }
    if (possible) ++res;
  }
  std::cout << res << std::endl;
  return 0;
}
