#include <iostream>
#include <vector>

int main() {
  int n, l, k;
  std::cin >> n >> l >> k;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  int left = 0, right = l;
  while (right - left > 1) {
    int mid = (left + right) / 2;
    int cnt = 1, cur = 0;
    for (int i = 0; i < n; ++i) {
      if (std::min(a[i] - cur, l - a[i]) >= mid) {
        ++cnt;
        cur = a[i];
      }
    }
    if (cnt >= k + 1) left = mid;
    else right = mid;
  }
  std::cout << left << std::endl;
  return 0;  
}
