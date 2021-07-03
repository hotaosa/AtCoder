#include <iostream>

int main() {
  long long n;
  std::cin >> n;

  long long saving = 0LL;
  int day = 0;
  while (saving < n) {
    ++day;
    saving += day;
  }

  std::cout << day << std::endl;
  return 0;
}
