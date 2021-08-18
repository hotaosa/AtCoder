#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<long long> s(n), t(n);
  for (int i = 0; i < n; ++i) std::cin >> s[i];
  for (int i = 0; i < n; ++i) std::cin >> t[i];

  for (int i = 0; i < 2; ++i) {
    t[0] = std::min(t[0], t[n - 1] + s[n - 1]);
    for (int j = 1; j < n; ++j) {
      t[j] = std::min(t[j], t[j - 1] + s[j - 1]);
    }
  }

  for (int res : t) std::cout << res << std::endl;
  return 0;
}
