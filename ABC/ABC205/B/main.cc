#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  std::sort(a.begin(), a.end());

  bool possible = true;
  for (int i = 0; i < n; ++i) if (a[i] != i + 1) possible = false;

  std::cout << (possible ? "Yes" : "No") << std::endl;
  return 0;
}
