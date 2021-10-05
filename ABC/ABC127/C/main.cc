#include <iostream>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> v(n, 0);
  for (int i = 0; i < m; ++i) {
    int l, r;
    std::cin >> l >> r;
    ++v[--l];
    if (r < n) --v[r];
  }

  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (i > 0) v[i] += v[i - 1];
    if (v[i] == m) ++res;
  }
  std::cout << res << std::endl;
  return 0;
}
