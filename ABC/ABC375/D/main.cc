#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string s;
  std::cin >> s;

  const std::size_t n = std::size(s);
  std::vector cnt_left(n, std::vector<long long>(26, 0));
  std::vector cnt_right(n, std::vector<long long>(26, 0));

  for (std::size_t i = 0; i < n; ++i) {
    if (i > 0) cnt_left[i] = cnt_left[i - 1];
    ++cnt_left[i][s[i] - 'A'];
  }

  for (int i = n - 1; i >= 0; --i) {
    if (i < (int)n - 1) cnt_right[i] = cnt_right[i + 1];
    ++cnt_right[i][s[i] - 'A'];
  }

  long long res = 0;
  for (std::size_t i = 1; i < n - 1; ++i) {
    for (std::size_t j = 0; j < 26; ++j) {
      res += cnt_left[i - 1][j] * cnt_right[i + 1][j];
    }
  }

  std::cout << res << "\n";
  return 0;
}