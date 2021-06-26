#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  long long res = n;
  int l = 0, r = 0;
  while (true) {
    while (r < n - 1 && a[r + 1] > a[r]) ++r;
    long long num = r - l + 1;
    res += num * (num - 1) / 2;
    if (r == n - 1) break;
    l = r = r + 1;
  }
  std::cout << res << std::endl;
  return 0;  
}
