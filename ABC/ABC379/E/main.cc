#include <iostream>
#include <string>
#include <vector>

int main() {
  int n;
  std::string s;
  std::cin >> n >> s;

  const int size = n * 2;
  std::vector<long long> count(size, 0);

  for (int i = 0; i < n; ++i) {
    long long add = (s[i] - '0') * (i + 1);
    count[0] += add;
    count[n - i] -= add;
  }
  for (int i = 1; i < size; ++i) {
    count[i] += count[i - 1];
  }

  for (int i = 0; i < size - 1; ++i) {
    count[i + 1] += count[i] / 10;
    count[i] %= 10;
  }
  while (count.back() == 0) count.pop_back();

  for (auto it = std::rbegin(count); it != std::rend(count); ++it) {
    std::cout << *it;
  }
  std::cout << "\n";

  return 0;
}
