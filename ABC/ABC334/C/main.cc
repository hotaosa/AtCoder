#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> a(k);
  for (auto &e : a) std::cin >> e;
  std::sort(a.begin(), a.end());

  if (k & 1) {
    std::vector<int> sum_d_left(k, 0);
    for (int i = 1; i < k; ++i) {
      sum_d_left[i] = sum_d_left[i - 1];
      if (i & 1) sum_d_left[i] += a[i] - a[i - 1];
    }
    std::vector<int> sum_d_right(k, 0);
    for (int i = k - 2; i >= 0; --i) {
      sum_d_right[i] = sum_d_right[i + 1];
      if ((k - 1 - i) & 1) sum_d_right[i] += a[i + 1] - a[i];
    }
    int res = 1 << 30;
    for (int i = 0; i < k; ++i) {
      int cur = 0;
      if (i > 0) cur += sum_d_left[i - 1];
      if (i < k - 1) cur += sum_d_right[i + 1];
      if (i & 1) cur += a[i + 1] - a[i - 1];
      res = std::min(res, cur);
    }
    std::cout << res << std::endl;
  } else {
    int res = 0;
    for (int i = 1; i < k; i += 2) {
      res += a[i] - a[i - 1];
    }
    std::cout << res << std::endl;
  }

  return 0;
}