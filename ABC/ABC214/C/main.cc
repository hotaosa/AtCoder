#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<long long> s(n), t(2 * n);
  for (int i = 0; i < n; ++i) std::cin >> s[i];
  for (int i = 0; i < n; ++i) {
    std::cin >> t[i];
    t[n + i] = t[i];
  }

  for (int i = 0; i < 2 * n - 1; ++i) {
    t[i + 1] = std::min(t[i + 1], t[i] + s[i % n]);
  }

  for (int i = n; i < 2 * n; ++i) std::cout << t[i] << std::endl;
  return 0;
}
