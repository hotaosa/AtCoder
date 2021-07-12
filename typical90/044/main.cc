#include <iostream>
#include <vector>

int main() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  int shift = 0;
  for (int i = 0; i < q; ++i) {
    int t, x, y;
    std::cin >> t >> x >> y;
    x = x - 1 - shift;
    while (x < 0) x += n;
    y = y - 1 - shift;
    while (y < 0) y += n;
    
    if (t == 1) std::swap(a[x], a[y]);
    else if (t == 2) ++shift;
    else  std::cout << a[x] << std::endl;
  }
  return 0;
}
