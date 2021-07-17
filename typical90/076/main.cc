#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  std::vector<long long> a(n + 1, 0);
  long long tot = 0LL;
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    tot += a[i];
  }
  for (int i = 1; i <= n; ++i) a.push_back(a[i]);

  if (tot % 10 != 0) { std::cout << "No" << std::endl; return 0; }
  tot = tot / 10 * 9;
  for (int i = 1; i < 2 * n; ++i) a[i + 1] += a[i];
  bool exist = false;
  for (int i = 1; i <= n; ++i) {
    if (*std::lower_bound(a.begin(), a.end(), tot + a[i - 1]) == tot + a[i - 1]) exist = true;
  }

  std::cout << (exist ? "Yes" : "No") << std::endl;
  return 0;  
}
