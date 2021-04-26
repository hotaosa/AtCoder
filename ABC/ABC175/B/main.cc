#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> l(n);
  for (int i = 0; i < n; ++i) std::cin >> l[i];
  std::sort(l.begin(), l.end());
  int res = 0;
  for (int i = 0; i < n - 2; ++i) {
    for (int j = i + 1; j < n - 1; ++j) {
      for (int k = j + 1; k < n; ++k) {
        if (l[i] != l[j] && l[j] != l[k] && l[k] < l[j] + l[i]) ++res;
      }
    }
  }
  std::cout << res << std::endl;
  return 0;
}
